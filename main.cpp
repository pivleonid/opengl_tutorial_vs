#include <iostream>

// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>


/*Ввод

Для достижения некоего контроля над вводом, мы можем воспользоваться функциями обратного вызова в GLFW.
Функции обратного вызова это указатели на функции, которые можно передать в GLFW, чтобы они были вызваны 
в нужное время. Одной из таких функций является KeyCallback, которая будет вызываться каждый раз, когда 
пользователь использует клавиатуру. Прототип этой функции выглядит следующим образом:*/
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

	/*Создаем объект окна. Этот объект содержит всю необходимую информацию об окне и используется функциями GLFW.*/
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	if (window == nullptr)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	//Зарегистрировать функцию обратного вызова надо после создания окна и до игрового цикла.
	glfwSetKeyCallback(window, key_callback);

	//ставить перед инициализацией GLEW
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	if (glewInit() != GLEW_OK)
	{
		std::cout << "Failed to initialize GLEW" << std::endl;
		return -1;
	}
	/* Прежде чем мы начнем что - либо отрисовывать нам надо еще кое что сделать.
	Нам нужно сообщить OpenGL размер отрисовываемого окна, чтобы OpenGL знал, как 
	мы хотим отображать данные и координаты относительно окна.Мы можем установить 
	эти значения через функцию glViewport. */
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);

	/*проверяет в начале каждой итерации цикла, получил ли GLFW инструкцию к закрытию*/
	//игровой цикл
	while (!glfwWindowShouldClose(window))
	{
		// Проверяем события и вызываем функции обратного вызова.
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		/*Двойная буферизация
Когда приложение отрисовывает в единственный буфер, то результирующее изображение может мерцать.
Причина такого поведения в том, что отрисовка происходит не мгновенно, а попиксельно сверху слева,
вправо вниз. Поскольку изображение отображается не мгновенно, а постепенно, то оно может иметь немало
артефактов. Для избежания этих проблем, оконные приложения используют двойную буферизация. 
Передний буфер содержит результирующее изображение, отображаемое пользователю, в это же время 
на задний буфер ведется отрисовка. Как только отрисовка будет закончена, эти буферы меняются местами
и изображение единовременно отображается пользователю.*/
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