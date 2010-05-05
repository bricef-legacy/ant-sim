/**
 * \file rules.c
 * \brief Functions created from tagged condition and filter rules.
 */

#include "header.h"

/** \fn int FLAME_integer_in_array(int a, int * b, int size)
 * \brief Returns 1 if an integer is a member of an integer array, else 0
 * \param a The integer to check.
 * \param b Pointer to the integer array.
 * \param size The size of the array
 * \return 1 for true, 0 for false.
 */
int FLAME_integer_in_array(int a, int * b, int size)
{
	int i;
	
	for(i = 0; i < size; i++)
	{
		if(a == b[i]) return 1;
	}
	
	return 0;
}

/** \fn void* cparams_create(int agent_number, int * agent_count, size_t * agent_struct_size, size_t * cparam_size)
 * \brief Create memory to hold agent filter variables for every agent using the filter on the current node.
 * \param agent_number The number of agent types.
 * \param agent_count List of the number of agents of each agent type.
 * \param agent_struct_size The struct size needed for each agent type.
 * \param cparam_size The size of the memory created.
 * \return Pointer to the created memory.
 */
void* cparams_create(int agent_number, int * agent_count, size_t * agent_struct_size, size_t * cparam_size)
{
	/* Pointer to the memory created that is going to be returned */
	void *data;
	/* Variable used in for loops */
	int i;
	/* Variable to hold total size of memory required for agent structures */
	size_t total_param_size = 0;

	/* For each agent type add required memory for agent structures */
	for(i = 0; i < agent_number; i++)
	{
		total_param_size += agent_count[i] * agent_struct_size[i];
	}

	//assert(count > 0);
	//assert(total_param_size > 0);
	/* Does libmboard free this memory? */
	
	/* Allocate required memory, where memory holds the number
	 * of each agent type, in order, and the total required
	 * memory for agent structures */
	data = malloc(agent_number*sizeof(int) + total_param_size);
	/* Make the memory size parameter equal to the actual memory size */
	*cparam_size = agent_number*sizeof(int) + total_param_size;
	/* Assert that the created memory was successfully created and not null */
	assert(data != NULL);

	/* Return the pointer to the created memory */
	return data;
}


/** \fn int FLAME_condition_Ant_stayInNest_01_04(xmachine_memory_Ant *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Ant_stayInNest_01_04(xmachine_memory_Ant *a)
{
	if(((a->state != 1) && (a->state != 2))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Ant_walk_01_02(xmachine_memory_Ant *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Ant_walk_01_02(xmachine_memory_Ant *a)
{
	if((a->state == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Ant_deposit_02_03(xmachine_memory_Ant *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Ant_deposit_02_03(xmachine_memory_Ant *a)
{
	if(((a->state == 1) || (a->state == 2))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Ant_depositIdle_02_04(xmachine_memory_Ant *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Ant_depositIdle_02_04(xmachine_memory_Ant *a)
{
	if(((a->state != 1) && (a->state != 2))) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Ant_forage_03_04(xmachine_memory_Ant *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Ant_forage_03_04(xmachine_memory_Ant *a)
{
	if((a->state == 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Ant_forageIdle_03_04(xmachine_memory_Ant *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Ant_forageIdle_03_04(xmachine_memory_Ant *a)
{
	if((a->state != 1)) return 1;
	else return 0;
}


/** \fn int FLAME_condition_Ant_findNest_01_02(xmachine_memory_Ant *a)
 * \brief The condition function for an agent function.
 * \param a The agent memory.
 * \return The success (1) or failure (0) of the condition.
 */
int FLAME_condition_Ant_findNest_01_02(xmachine_memory_Ant *a)
{
	if((a->state == 2)) return 1;
	else return 0;
}





