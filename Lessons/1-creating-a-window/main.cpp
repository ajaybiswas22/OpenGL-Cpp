#include"libs.h"

void framebuffer_resize_callback(GLFWwindow* window, int fbW, int fbH)
{
	glViewport(0, 0, fbW, fbH);
}

int main(void)
{
	//INIT GLFW
	glfwInit();

	//CREATE WINDOW
	const int WINDOW_WIDTH = 640;
	const int WINDOW_HEIGHT = 480;
	int framebufferWidth = 0;
	int framebufferHeight = 0;

	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT,GL_TRUE); MAC OS

	GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "YOUTUBE_TUTORIAL", NULL, NULL);

	glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);
	//glfwGetFramebufferSize(window, &framebufferWidth, &framebufferHeight);
	//glViewport(0, 0, framebufferWidth, framebufferHeight);

	glfwMakeContextCurrent(window);  //IMPORTANT!!

	//INIT GLEW (NEEDS WINDOW AND OPENGL CONTEXT)
	glewExperimental = GL_TRUE;

	//Error
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error::MAIN.CPP::GLEW_INIT_FAILED" << "\n";
		glfwTerminate();
	}

	//MAIN LOOP
	while (!glfwWindowShouldClose(window))
	{
		//UPDATE INPUT
		glfwPollEvents();	// allows you to close window

		//UPDATE

		//Draw
		//Clear
		glClearColor(0.f, 0.f, 0.f, 1.f);	//RGBA
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

		//Draw


		//END Draw
		glfwSwapBuffers(window);	// (back buffer, front buffer) (drawing, showing)
		glFlush();
	}


	//END OF PROGRAM
	
	glfwTerminate();

	return 0;
}