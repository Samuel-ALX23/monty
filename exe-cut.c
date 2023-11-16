#include "monty.h"

/**
 * @brief Processes a single instruction from the bytecode file and executes the corresponding functionality.
 * @param instruction The instruction string containing the opcode and optional argument.
 * @param stack Pointer to the head of the linked list stack.
 * @param instruction_number The line number in the bytecode file where the instruction appears.
 * @param bytecode_file The open bytecode file containing the instructions.
 */

int process_instruction(char *instruction, stack_t **stack, unsigned int instruction_number, FILE *bytecode_file)
{
	instruction_t opcodes[] = {
		{"push", pushElement},
		{"pall", print_all_stack_values},
		{"pint", print_integer},
		{"pop", f_pop},
		{"swap", swap_top_two_elements},
		{"add", handle_add_stack},
		{"nop", _nop_handle},
		{"sub", subtract_top_two_elements},
		{"div", divide_elements},
		{"mul", handle_mudulo},
		{"mod", handle_modulo},
		{"pchar", dis_character},
		{"pstr", _string_dis},
		{"rotl", f_rotate_left},
		{"rotr", rotate_right},
		{"queue", set_lifi_to_queue},
		{"stack", set_lifo},
		{NULL, NULL}
	};

	opcodes[0].func = handle_push;

	unsigned int index = 0;
	char *opcode;
	char *argument;

	opcode = strtok(instruction, " \n\t");
	argument = strtok(NULL, " \n\t");

	if (opcode && opcode[0] == '#')
	{
		return (0);
	}

	while (opcodes[index].opcode && opcode)
	{
		if (strcmp(opcode, opcodes[index].opcode) == 0)
		{
			opcodes[index].handler(stack, argument, instruction_number);
			return (0);
		}
		index++;
	}

	if (opcode && opcodes[index].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", instruction_number, opcode);
		fclose(bytecode_file);
		free(instruction);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	return (1);
}
