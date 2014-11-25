#include <GeKo_Graphics/Renderer/Renderer.h>
#include <GeKo_Graphics/Shader/Shader.h>
#include <GeKo_Graphics/Object/Cube.h>
#include <GeKo_Graphics/Camera/Camera.h>
#include <GeKo_Graphics/Camera/Trackball.h>
#include <GeKo_Gameplay/Input/InputHandler.h>
#include <GeKo_Gameplay/Input/InputMap.h>
#include <GeKo_Graphics/Object/Teapot.h>
#include <GeKo_Graphics/Material/Texture.h>
#include <GeKo_Graphics/Scenegraph/Scene.h>
#include <GeKo_Graphics/Scenegraph/Node.h>
#include <GeKo_Graphics/Shader/FBO.h>
#include <GeKo_Graphics/Scenegraph/Level.h>

InputHandler iH;
Trackball cam(800, 800);

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
	std::map<int, std::function<void()>> activeMap = iH.getActiveInputMap()->getMap();

	for (std::map<int, std::function<void()>>::iterator it = activeMap.begin(); it != activeMap.end(); it++){
		if (it->first == key)
			activeMap.at(key)();
		if (it == activeMap.end())
			std::cout << "Key is not mapped to an action" << std::endl;
	}
}

int main()
{
	glfwInit();

	//our window
	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "Camera Test", NULL, NULL);
	glfwMakeContextCurrent(window);


	//Set Camera to another position
	cam.setPosition(glm::vec4(0.0,0.0,10.0,1.0));
	cam.setName("TrackballCam");
	
	//Set all InputMaps and set one InputMap active
	iH.setAllInputMaps(cam);
	iH.changeActiveInputMap("Trackball");

	//Callback
	glfwSetKeyCallback(window, key_callback);


    glewInit();

	//our shader
    VertexShader vs(loadShaderSource(SHADERS_PATH + std::string("/TextureShader3D/TextureShader3D.vert")));
    FragmentShader fs(loadShaderSource(SHADERS_PATH + std::string("/TextureShader3D/TextureShader3D.frag")));
	ShaderProgram shader(vs, fs);

	//our renderer
    OpenGL3Context context;
    Renderer renderer(context);

	//our object
	 Cube cube;
	 Teapot tea;
	 Rect rect;
	 rect.loadBufferData();

	 //our textures
	 Texture texCV((char*)RESOURCES_PATH "/cv_logo.bmp");
	 Texture tex((char*)RESOURCES_PATH "/brick.bmp");

	 //Scenegraph creation 
	 Level testLevel("testLevel");
	 Scene testScene("testScene");
	 testLevel.addScene(testScene);
	 testLevel.changeScene("testScene");

	 Node testNode("testNode");
	 testNode.addGeometry(&tea);

	 testNode.addTexture(&texCV);
	 testNode.setModelMatrix(glm::translate(testNode.getModelMatrix(), glm::vec3(0.0, 0.0, 0.0)));

	 Node testNodeChild("child1");
     testNodeChild.addGeometry(&cube);

	 testNodeChild.addTexture(&tex);
	 testNodeChild.setModelMatrix(glm::translate(testNodeChild.getModelMatrix(), glm::vec3(3.0, 0.0, 0.0)));
	
	 testScene.getScenegraph()->getRootNode()->addChildrenNode(testNode);

	 testNode.addChildrenNode(testNodeChild);
	 testNodeChild.setParentNode(&testNode);

	 testNode.getChildrenNode("child1")->getNodeName();

	//testNodeChild.getParentNode()->getNodeName();


	 FBO fbo(800, 600, 3, true, false);

    //Renderloop
    while (!glfwWindowShouldClose(window))
    {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glEnable(GL_DEPTH_TEST);

		shader.bind();
		shader.sendMat4("viewMatrix", cam.getViewMatrix());
		shader.sendMat4("projectionMatrix", cam.getProjectionMatrix());
		
		shader.sendSampler2D("testTexture", testNode.getTexture()->getTexture());
		testNode.setModelMatrix(glm::rotate(testNode.getModelMatrix(), 0.02f, glm::vec3(0.0, 1.0, 0.0)));
		shader.sendMat4("modelMatrix", testNode.getModelMatrix());
		testScene.getScenegraph()->getRootNode()->getChildrenNode("testNode")->render();

		shader.sendSampler2D("testTexture", testNodeChild.getTexture()->getTexture());
		shader.sendMat4("modelMatrix", testNode.getModelMatrix() * testNodeChild.getModelMatrix());
		testNodeChild.render();
		shader.unbind();
       
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}