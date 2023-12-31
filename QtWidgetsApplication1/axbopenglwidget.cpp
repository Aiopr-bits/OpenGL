#include "axbopenglwidget.h"

unsigned int VBO, VAO, EBO;
float vertices[] = {
	// positions      // colors        // texture coords
	0.3f, 0.3f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // top right
	0.3f, -0.3f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // bottom right
	-0.3f, -0.3f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
	-0.3f, 0.3f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // top left
};


unsigned int indices[] = { // note that we start from 0!
0, 1, 3, // first triangle
1, 2, 3 // second triangle
};

AXBOpenGLWidget::AXBOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
	setFocusPolicy(Qt::StrongFocus);
	QObject::connect(&timer, SIGNAL(timeout()), this, SLOT(on_timeout()));
	timer.start(10);
}

AXBOpenGLWidget::~AXBOpenGLWidget()
{
	makeCurrent();
    glDeleteBuffers(1,&VBO);
	glDeleteBuffers(1,&EBO);
    glDeleteVertexArrays(1,&VAO);
    doneCurrent();
}

void AXBOpenGLWidget::drawShape(Shape shape)
{
	m_shape=shape;
    update();
}

void AXBOpenGLWidget::setWirefame(bool wireframe)
{
	makeCurrent();
	if (wireframe)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	else
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	update();
	doneCurrent();
}

void AXBOpenGLWidget::initializeGL()
{
	//初始化OpenGL函数
	initializeOpenGLFunctions();

	//创建着色器程序对象
	bool success;
	shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, "./shaders/shapes.vert");
	shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, "./shaders/shapes.frag");

	success = shaderProgram.link();
	if (!success)
		qDebug() << "ERR:" << shaderProgram.log();

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	textureWall = new QOpenGLTexture(QImage("./images/wall.jpg").mirrored());
	textureSmile = new QOpenGLTexture(QImage("./images/awesomeface.png").mirrored());
	textureSmall = new QOpenGLTexture(QImage("./images/small.png").mirrored());

	shaderProgram.bind();
	shaderProgram.setUniformValue("textureWall", 0);
	shaderProgram.setUniformValue("textureSmile", 1);
	shaderProgram.setUniformValue("textureSmall", 2);

	//创建VBO和VAO对象，并赋予ID
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	//绑定VBO和VAO对象
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//为当前绑定到target的缓冲区对象创建一个新的数据存储。
	//如果data不是NULL，则使用来自此指针的数据初始化数据存储
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//告知显卡如何解析缓冲里的属性值
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//解绑VBO对象
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//创建EBO对象，并赋予ID
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//增加纹理环绕方式
	textureSmall->bind(2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	//增加纹理过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);


	
	glBindVertexArray(0);
}

void AXBOpenGLWidget::resizeGL(int w, int h)
{
	Q_UNUSED(w); Q_UNUSED(h);
}

void AXBOpenGLWidget::paintGL()
{
	QMatrix4x4 theMatrix;
	unsigned int time = QTime::currentTime().msec();

	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	shaderProgram.bind();
	glBindVertexArray(VAO);

	switch (m_shape) {
    case Rect:
		textureWall->bind(0);
		textureSmile->bind(1);
		textureSmall->bind(2);

		theMatrix.translate(0.5, -0.5, 0);
		theMatrix.rotate(time, QVector3D(0.0f, 0.0f, 1.0f));
		shaderProgram.setUniformValue("theMatrix", theMatrix);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);

		theMatrix.setToIdentity();
		theMatrix.translate(-0.5, 0.5, 0);
		theMatrix.scale(fabs(sin(time)));
		shaderProgram.setUniformValue("theMatrix", theMatrix);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, NULL);
        break;
    default:
        break;
    }
}

void AXBOpenGLWidget::on_timeout()
{
	update();
}
