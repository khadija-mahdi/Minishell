# ifndef TYPES_H
# define TYPES_H
typedef struct node
{
	int input_file;
	char *command;
	char **arguments;
	int output_file;
	// int	shlvl;
} m_node;

enum file_input
{
	NONE = -3,
	NO_FILE = -1,
	ERROR = -2,
};
enum EXIT_STATUS
{
	M_SIG_INT = 78
};
#endif