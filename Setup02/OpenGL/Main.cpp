#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	// Init GLFW
	glfwInit();

	// Tell GLFW the version of OpenGL
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW to use CORE profile
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// window hegiht and width
	int windowHeight = 800;
	int windowWidth = 800;

	// create GLFWwindow object
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Hello!", NULL, NULL);

	// error handling
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window!" << std::endl;
		glfwTerminate();

		return -1;
	}

	// add window to current context
	glfwMakeContextCurrent(window);

	// load GLAD to configure OpenGL
	gladLoadGL();

	//Specify viewport to OpenGL
	// from x = 0, y = 0, to x = windowWidth, y = windowHeight
	glViewport(0, 0, windowWidth, windowHeight);

	// background color RGBA (0 to 1)
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	// clean back buffer and assing the new color
	glClear(GL_COLOR_BUFFER_BIT);
	// swap back buffer with front buffer
	glfwSwapBuffers(window);

	// main while loop
	while (!glfwWindowShouldClose(window))
	{
		// takes care of all GLFW events
		glfwPollEvents();
	}

	// delete window before closing
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}