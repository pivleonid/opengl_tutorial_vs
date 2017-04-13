#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>


/*����

��� ���������� ������� �������� ��� ������, �� ����� ��������������� ��������� ��������� ������ � GLFW.
������� ��������� ������ ��� ��������� �� �������, ������� ����� �������� � GLFW, ����� ��� ���� ������� 
� ������ �����. ����� �� ����� ������� �������� KeyCallback, ������� ����� ���������� ������ ���, ����� 
������������ ���������� ����������. �������� ���� ������� �������� ��������� �������:*/
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);

// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
bool flag_color;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	std::cout << "Starting GLFW context, OpenGL 3.3" << std::endl;
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	/*������� ������ ����. ���� ������ �������� ��� ����������� ���������� �� ���� � ������������ ��������� GLFW.*/
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	//���������������� ������� ��������� ������ ���� ����� �������� ���� � �� �������� �����.
	glfwSetKeyCallback(window, key_callback);

	//������� ����� �������������� GLEW
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	/* ������ ��� �� ������ ��� - ���� ������������ ��� ���� ��� ��� ��� �������.
	��� ����� �������� OpenGL ������ ��������������� ����, ����� OpenGL ����, ��� 
	�� ����� ���������� ������ � ���������� ������������ ����.�� ����� ���������� 
	��� �������� ����� ������� glViewport. */
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	/*��������� � ������ ������ �������� �����, ������� �� GLFW ���������� � ��������*/
	//������� ����
	while (!glfwWindowShouldClose(window))
	{
		// ��������� ������� � �������� ������� ��������� ������.
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/*������� �����������
����� ���������� ������������ � ������������ �����, �� �������������� ����������� ����� �������.
������� ������ ��������� � ���, ��� ��������� ���������� �� ���������, � ����������� ������ �����,
������ ����. ��������� ����������� ������������ �� ���������, � ����������, �� ��� ����� ����� ������
����������. ��� ��������� ���� �������, ������� ���������� ���������� ������� �����������. 
�������� ����� �������� �������������� �����������, ������������ ������������, � ��� �� ����� 
�� ������ ����� ������� ���������. ��� ������ ��������� ����� ���������, ��� ������ �������� �������
� ����������� ������������� ������������ ������������.*/
		glfwSwapBuffers(window);
	}

	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}

// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	std::cout << key << std::endl;
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}