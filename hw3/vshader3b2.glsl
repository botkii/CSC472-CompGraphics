#version 330

in vec3 a_Position;	// attribute variable: position vector

uniform mat4 u_View;		// uniform variable for view matrix
uniform mat4 u_Projection;	// uniform variable for projection matrix

void main() 
{
	gl_Position = u_Projection * u_View * vec4(a_Position, 1.0);
}
