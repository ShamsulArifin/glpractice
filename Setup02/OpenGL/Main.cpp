#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "shaderClass.h"
#include "VAO.h"
#include "VBO.h"
#include "EBO.h"

// Vertices coordinates
GLfloat vertices[] =
{
	-0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,	// Lower left corner
	0.5f, -0.5f * float(sqrt(3)) / 3, 0.0f,		// Lower right corner
	0.0f, 0.5f * float(sqrt(3)) * 2 / 3, 0.0f,	// Upper corner
	-0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,	// Inner left
	0.5f / 2, 0.5f * float(sqrt(3)) / 6, 0.0f,	// Inner right
	0.0f, -0.5f * float(sqrt(3)) / 3, 0.0f	// Inner down
};

GLuint indices[] =
{
	0, 3, 5,	// Lower left triangle
	3, 2, 4,	// Lower right triangle
	5, 4, 1		// Upper triangle
};

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

	
	// generates shader object
	Shader shaderProgram("default.vert", "default.frag");

	// Genrates vertex array object and binds it
	VAO VAO1;
	VAO1.Bind();

	// Generates VBO
	VBO VBO1(vertices, sizeof(vertices));
	// Generates EBO
	EBO EBO1(indices, sizeof(indices));

	// Links VBO to VAO
	VAO1.LinkVBO(VBO1, 0);

	// Unbind all to prevent modifying
	VAO1.Unbind();
	VBO1.Unbind();
	EBO1.Unbind();

	// main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color
		glClear(GL_COLOR_BUFFER_BIT);
		// Specify OpenGL which shader program to run
		shaderProgram.Activate();
		VAO1.Bind();
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);

		// takes care of all GLFW events
		glfwPollEvents();
	}

	// Delete all
	VAO1.Delete();
	VBO1.Delete();
	EBO1.Delete();
	shaderProgram.Delete();

	// delete window before closing
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}