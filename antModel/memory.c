/**
 * \file  memory.c
 * \brief Holds memory functions.
 */

#include "header.h"


void unittest_updateState_00_01()
{
	
	
	//return updateState();
}

void unittest_stayInNest_01_04()
{
	
	
	//return stayInNest();
}

void unittest_walk_01_02()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_pheromoneInformation, &i_pheromoneInformation);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'pheromoneInformation'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'pheromoneInformation' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pheromoneInformation' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	
	rc = MB_Iterator_Create(b_foodInformation, &i_foodInformation);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'foodInformation'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'foodInformation' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'foodInformation' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return walk();
}

void unittest_deposit_02_03()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_pheromoneInformation, &i_pheromoneInformation);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'pheromoneInformation'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'pheromoneInformation' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pheromoneInformation' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return deposit();
}

void unittest_depositIdle_02_04()
{
	
	
	//return depositIdle();
}

void unittest_forage_03_04()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_foodInformation, &i_foodInformation);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'foodInformation'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'foodInformation' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'foodInformation' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return forage();
}

void unittest_forageIdle_03_04()
{
	
	
	//return forageIdle();
}

void unittest_decreaseFoodLevel_04_05()
{
	
	
	//return decreaseFoodLevel();
}

void unittest_findNest_01_02()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_nestInformation, &i_nestInformation);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'nestInformation'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'nestInformation' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'nestInformation' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	
	rc = MB_Iterator_Create(b_pheromoneInformation, &i_pheromoneInformation);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'pheromoneInformation'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'pheromoneInformation' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pheromoneInformation' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return findNest();
}

void unittest_pheromoneInformation_00_01()
{
	
	
	//return pheromoneInformation();
}

void unittest_decreasePheromoneLife_01_02()
{
	
	
	//return decreasePheromoneLife();
}

void unittest_increasePheromoneLife_02_03()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_pheromoneIncreased, &i_pheromoneIncreased);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'pheromoneIncreased'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'pheromoneIncreased' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pheromoneIncreased' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return increasePheromoneLife();
}

void unittest_produce_00_01()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_newPheromoneInput, &i_newPheromoneInput);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'newPheromoneInput'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'newPheromoneInput' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'newPheromoneInput' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return produce();
}

void unittest_produceFood_00_01()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_newFood, &i_newFood);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'newFood'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'newFood' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'newFood' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return produceFood();
}

void unittest_nestInformation_00_01()
{
	
	
	//return nestInformation();
}

void unittest_foodInformation_00_01()
{
	
	
	//return foodInformation();
}

void unittest_updateFood_01_02()
{
	int rc;
	
	
	rc = MB_Iterator_Create(b_foodEaten, &i_foodEaten);
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Could not create Iterator for 'foodEaten'\n");
	   switch(rc) {
	       case MB_ERR_INVALID:
	           fprintf(stderr, "\t reason: 'foodEaten' board is invalid\n");
	           break;
	       case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'foodEaten' board is locked\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	   }
	}
	#endif
	
	//return updateFood();
}


void free_messages()
{
	int rc;
	
	    rc = MB_Clear(b_pheromoneInformation);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'pheromoneInformation' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'pheromoneInformation' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'pheromoneInformation' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_newPheromoneInput);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'newPheromoneInput' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'newPheromoneInput' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'newPheromoneInput' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_foodInformation);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'foodInformation' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'foodInformation' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'foodInformation' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_foodEaten);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'foodEaten' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'foodEaten' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'foodEaten' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_newFood);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'newFood' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'newFood' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'newFood' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_pheromoneIncreased);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'pheromoneIncreased' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'pheromoneIncreased' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'pheromoneIncreased' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	    rc = MB_Clear(b_nestInformation);
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not clear 'nestInformation' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: 'nestInformation' board is invalid\n");
	               break;
	           case MB_ERR_LOCKED:
	               fprintf(stderr, "\t reason: 'nestInformation' board is locked\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Clear returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
}

/** \fn void initialise_pointers()
 * \brief Initialises pointers to xmachine, message, and node lists.
 */
void initialise_pointers()
{
int rc;

	/* Initialise message sync composite params as NULL */
	FLAME_m_pheromoneInformation_composite_params = NULL;

	    rc = MB_Create(&b_pheromoneInformation, sizeof(m_pheromoneInformation));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'pheromoneInformation' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_newPheromoneInput_composite_params = NULL;

	    rc = MB_Create(&b_newPheromoneInput, sizeof(m_newPheromoneInput));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'newPheromoneInput' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_foodInformation_composite_params = NULL;

	    rc = MB_Create(&b_foodInformation, sizeof(m_foodInformation));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'foodInformation' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_foodEaten_composite_params = NULL;

	    rc = MB_Create(&b_foodEaten, sizeof(m_foodEaten));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'foodEaten' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_newFood_composite_params = NULL;

	    rc = MB_Create(&b_newFood, sizeof(m_newFood));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'newFood' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_pheromoneIncreased_composite_params = NULL;

	    rc = MB_Create(&b_pheromoneIncreased, sizeof(m_pheromoneIncreased));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'pheromoneIncreased' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	/* Initialise message sync composite params as NULL */
	FLAME_m_nestInformation_composite_params = NULL;

	    rc = MB_Create(&b_nestInformation, sizeof(m_nestInformation));
	    #ifdef ERRCHECK
	    if (rc != MB_SUCCESS)
	    {
	       fprintf(stderr, "ERROR: Could not create 'nestInformation' board\n");
	       switch(rc) {
	           case MB_ERR_INVALID:
	               fprintf(stderr, "\t reason: Invalid message size\n");
	               break;
	           case MB_ERR_MEMALLOC:
	               fprintf(stderr, "\t reason: out of memory\n");
	               break;
	           case MB_ERR_INTERNAL:
	               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
	               break;
	           default:
                   fprintf(stderr, "\t MB_Create returned error code: %d (see libmboard docs for details)\n", rc);
                   break;
	       }

	       
       	   exit(rc);
	    }
	    #endif
	
	Ant_05_state = init_Ant_state();

	Ant_03_state = init_Ant_state();

	Ant_02_state = init_Ant_state();

	Ant_04_state = init_Ant_state();

	Ant_01_state = init_Ant_state();

	Ant_00_state = init_Ant_state();

	Pheromone_03_state = init_Pheromone_state();

	Pheromone_02_state = init_Pheromone_state();

	Pheromone_01_state = init_Pheromone_state();

	Pheromone_00_state = init_Pheromone_state();

	Generator_01_state = init_Generator_state();

	Generator_00_state = init_Generator_state();

	FoodGenerator_01_state = init_FoodGenerator_state();

	FoodGenerator_00_state = init_FoodGenerator_state();

	Nest_01_state = init_Nest_state();

	Nest_00_state = init_Nest_state();

	Food_02_state = init_Food_state();

	Food_01_state = init_Food_state();

	Food_00_state = init_Food_state();

	temp_node_info = NULL;
	p_node_info = &temp_node_info;
}

/** \fn void initialise_unit_testing()
 * \brief Initialises framework for unit testing.
 */
void initialise_unit_testing()
{
	int rc;

	rc = MB_Env_Init();
	#ifdef ERRCHECK
	if (rc != MB_SUCCESS)
	{
	   fprintf(stderr, "ERROR: Failed to initialise Message Board environment\n");
	   switch(rc) {
	       case MB_ERR_MPI:
	           fprintf(stderr, "\t reason: MPI library not initialised\n");
	           break;
	       case MB_ERR_MEMALLOC:
	           fprintf(stderr, "\t reason: out of memory\n");
	           break;
	       default:
               fprintf(stderr, "\t MB_Env_Init returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);

	}
	#endif

	initialise_pointers();
}

FLAME_output * add_FLAME_output(FLAME_output ** outputs)
{
	FLAME_output * current;

	current = (FLAME_output *)malloc(sizeof(FLAME_output));
	CHECK_POINTER(current);
	current->next = *outputs;
	*outputs = current;

	current->type = -1;
	current->format = -1;
	current->location = NULL;
	current->period = -1;
	current->phase = -1;

	return current;
}

void free_FLAME_outputs(FLAME_output ** outputs)
{
	FLAME_output * current, * next;

	current = *outputs;
	while(current)
	{
		next = current->next;
		free(current->location);
		free(current);
		current = next;
	}
	*outputs = NULL;
}

/* add_location */
/** \fn void add_location(double point, location ** p_location)
 * \brief Adds a location in order into the location list.
 * \param point Position of an agent.
 * \param p_location Pointer Pointer to the location list.
 */
void add_location(double point, location ** p_location)
{
	location * current = *p_location;
	location * tmp = NULL;
	location * newlocation = NULL;
	int found = 0;

	while(found == 0)
	{
		if(current == NULL) found = 1;
		else if(point > current->point) found = 1;
		else
		{
			tmp = current;
			current = current->next;
		}
	}

	newlocation = (location *)malloc(sizeof(location));
	CHECK_POINTER(newlocation);
	if(tmp)
	{
		tmp->next = newlocation;
	}
	else
	{
		*p_location = newlocation;
	}

	newlocation->next = current;
	newlocation->point = point;
}

/* freelocations */
/** \fn void freelocations(location ** p_location)
 * \brief Free locations from the location list.
 * \param p_location Pointer Pointer to the location list.
 */
void freelocations(location ** p_location)
{
	location * head = *p_location;
	location * tmp = NULL;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	*p_location = NULL;
}

void init_int_static_array(int * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0;
}

void init_float_static_array(float * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_double_static_array(double* array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = 0.0;
}

void init_char_static_array(char * array, int size)
{
	int i;

	for(i = 0; i < size; i++) array[i] = '\0';
}




xmachine_memory_Ant_state * init_Ant_state()
{
	xmachine_memory_Ant_state * current = (xmachine_memory_Ant_state *)malloc(sizeof(xmachine_memory_Ant_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_Ant * init_Ant_agent()
{
	xmachine_memory_Ant * current = (xmachine_memory_Ant *)malloc(sizeof(xmachine_memory_Ant));
	CHECK_POINTER(current);

	current->antID = 0;
	current->antX = 0.0;
	current->antY = 0.0;
	current->foodLevel = 0.0;
	current->isFed = 0;
	current->isInNest = 0;
	current->antDirection = 0;
	current->state = 0;
	current->lastFoodConc = 0.0;

	return current;
}

void free_Ant_agent(xmachine_memory_Ant_holder * tmp, xmachine_memory_Ant_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_Ant_agent()
{
	current_xmachine_Ant = (xmachine_memory_Ant *)malloc(sizeof(xmachine_memory_Ant));
	CHECK_POINTER(current);

		current_xmachine_Ant->antID = 0;
		current_xmachine_Ant->antX = 0.0;
		current_xmachine_Ant->antY = 0.0;
		current_xmachine_Ant->foodLevel = 0.0;
		current_xmachine_Ant->isFed = 0;
		current_xmachine_Ant->isInNest = 0;
		current_xmachine_Ant->antDirection = 0;
		current_xmachine_Ant->state = 0;
		current_xmachine_Ant->lastFoodConc = 0.0;
	
}

void unittest_free_Ant_agent()
{
	
	free(current_xmachine_Ant);
}

void free_Ant_agents()
{
	current_xmachine_Ant_holder = Ant_05_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		free_Ant_agent(current_xmachine_Ant_holder, Ant_05_state);
		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	current_xmachine_Ant_holder = Ant_03_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		free_Ant_agent(current_xmachine_Ant_holder, Ant_03_state);
		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	current_xmachine_Ant_holder = Ant_02_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		free_Ant_agent(current_xmachine_Ant_holder, Ant_02_state);
		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	current_xmachine_Ant_holder = Ant_04_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		free_Ant_agent(current_xmachine_Ant_holder, Ant_04_state);
		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	current_xmachine_Ant_holder = Ant_01_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		free_Ant_agent(current_xmachine_Ant_holder, Ant_01_state);
		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	current_xmachine_Ant_holder = Ant_00_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		free_Ant_agent(current_xmachine_Ant_holder, Ant_00_state);
		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
}

void free_Ant_states()
{
	free(Ant_05_state);
	free(Ant_03_state);
	free(Ant_02_state);
	free(Ant_04_state);
	free(Ant_01_state);
	free(Ant_00_state);
}

void transition_Ant_agent(xmachine_memory_Ant_holder * tmp, xmachine_memory_Ant_state * from_state, xmachine_memory_Ant_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_Ant_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Ant_agent_internal(xmachine_memory_Ant * agent, xmachine_memory_Ant_state * state)
{
	xmachine_memory_Ant_holder * current = (xmachine_memory_Ant_holder *)malloc(sizeof(xmachine_memory_Ant_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_Ant_agent(int antID, double antX, double antY, double foodLevel, int isFed, int isInNest, int antDirection, int state, double lastFoodConc)
 * \brief Add Ant X-machine to the current being used X-machine list.
 * \param antID Variable for the X-machine memory.
 * \param antX Variable for the X-machine memory.
 * \param antY Variable for the X-machine memory.
 * \param foodLevel Variable for the X-machine memory.
 * \param isFed Variable for the X-machine memory.
 * \param isInNest Variable for the X-machine memory.
 * \param antDirection Variable for the X-machine memory.
 * \param state Variable for the X-machine memory.
 * \param lastFoodConc Variable for the X-machine memory.
 */
void add_Ant_agent(int antID, double antX, double antY, double foodLevel, int isFed, int isInNest, int antDirection, int state, double lastFoodConc)
{
	xmachine_memory_Ant * current;

	current = init_Ant_agent();
	add_Ant_agent_internal(current, current_xmachine_Ant_next_state);

	current->antID = antID;
	current->antX = antX;
	current->antY = antY;
	current->foodLevel = foodLevel;
	current->isFed = isFed;
	current->isInNest = isInNest;
	current->antDirection = antDirection;
	current->state = state;
	current->lastFoodConc = lastFoodConc;
}

xmachine_memory_Pheromone_state * init_Pheromone_state()
{
	xmachine_memory_Pheromone_state * current = (xmachine_memory_Pheromone_state *)malloc(sizeof(xmachine_memory_Pheromone_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_Pheromone * init_Pheromone_agent()
{
	xmachine_memory_Pheromone * current = (xmachine_memory_Pheromone *)malloc(sizeof(xmachine_memory_Pheromone));
	CHECK_POINTER(current);

	current->pheromoneID = 0;
	current->life = 0.0;
	current->pheromoneX = 0.0;
	current->pheromoneY = 0.0;

	return current;
}

void free_Pheromone_agent(xmachine_memory_Pheromone_holder * tmp, xmachine_memory_Pheromone_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_Pheromone_agent()
{
	current_xmachine_Pheromone = (xmachine_memory_Pheromone *)malloc(sizeof(xmachine_memory_Pheromone));
	CHECK_POINTER(current);

		current_xmachine_Pheromone->pheromoneID = 0;
		current_xmachine_Pheromone->life = 0.0;
		current_xmachine_Pheromone->pheromoneX = 0.0;
		current_xmachine_Pheromone->pheromoneY = 0.0;
	
}

void unittest_free_Pheromone_agent()
{
	
	free(current_xmachine_Pheromone);
}

void free_Pheromone_agents()
{
	current_xmachine_Pheromone_holder = Pheromone_03_state->agents;
	while(current_xmachine_Pheromone_holder)
	{
		temp_xmachine_Pheromone_holder = current_xmachine_Pheromone_holder->next;
		free_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_03_state);
		current_xmachine_Pheromone_holder = temp_xmachine_Pheromone_holder;
	}
	current_xmachine_Pheromone_holder = Pheromone_02_state->agents;
	while(current_xmachine_Pheromone_holder)
	{
		temp_xmachine_Pheromone_holder = current_xmachine_Pheromone_holder->next;
		free_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_02_state);
		current_xmachine_Pheromone_holder = temp_xmachine_Pheromone_holder;
	}
	current_xmachine_Pheromone_holder = Pheromone_01_state->agents;
	while(current_xmachine_Pheromone_holder)
	{
		temp_xmachine_Pheromone_holder = current_xmachine_Pheromone_holder->next;
		free_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_01_state);
		current_xmachine_Pheromone_holder = temp_xmachine_Pheromone_holder;
	}
	current_xmachine_Pheromone_holder = Pheromone_00_state->agents;
	while(current_xmachine_Pheromone_holder)
	{
		temp_xmachine_Pheromone_holder = current_xmachine_Pheromone_holder->next;
		free_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_00_state);
		current_xmachine_Pheromone_holder = temp_xmachine_Pheromone_holder;
	}
}

void free_Pheromone_states()
{
	free(Pheromone_03_state);
	free(Pheromone_02_state);
	free(Pheromone_01_state);
	free(Pheromone_00_state);
}

void transition_Pheromone_agent(xmachine_memory_Pheromone_holder * tmp, xmachine_memory_Pheromone_state * from_state, xmachine_memory_Pheromone_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_Pheromone_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Pheromone_agent_internal(xmachine_memory_Pheromone * agent, xmachine_memory_Pheromone_state * state)
{
	xmachine_memory_Pheromone_holder * current = (xmachine_memory_Pheromone_holder *)malloc(sizeof(xmachine_memory_Pheromone_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_Pheromone_agent(int pheromoneID, double life, double pheromoneX, double pheromoneY)
 * \brief Add Pheromone X-machine to the current being used X-machine list.
 * \param pheromoneID Variable for the X-machine memory.
 * \param life Variable for the X-machine memory.
 * \param pheromoneX Variable for the X-machine memory.
 * \param pheromoneY Variable for the X-machine memory.
 */
void add_Pheromone_agent(int pheromoneID, double life, double pheromoneX, double pheromoneY)
{
	xmachine_memory_Pheromone * current;

	current = init_Pheromone_agent();
	add_Pheromone_agent_internal(current, current_xmachine_Pheromone_next_state);

	current->pheromoneID = pheromoneID;
	current->life = life;
	current->pheromoneX = pheromoneX;
	current->pheromoneY = pheromoneY;
}

xmachine_memory_Generator_state * init_Generator_state()
{
	xmachine_memory_Generator_state * current = (xmachine_memory_Generator_state *)malloc(sizeof(xmachine_memory_Generator_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_Generator * init_Generator_agent()
{
	xmachine_memory_Generator * current = (xmachine_memory_Generator *)malloc(sizeof(xmachine_memory_Generator));
	CHECK_POINTER(current);

	current->memoryID = 0;

	return current;
}

void free_Generator_agent(xmachine_memory_Generator_holder * tmp, xmachine_memory_Generator_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_Generator_agent()
{
	current_xmachine_Generator = (xmachine_memory_Generator *)malloc(sizeof(xmachine_memory_Generator));
	CHECK_POINTER(current);

		current_xmachine_Generator->memoryID = 0;
	
}

void unittest_free_Generator_agent()
{
	
	free(current_xmachine_Generator);
}

void free_Generator_agents()
{
	current_xmachine_Generator_holder = Generator_01_state->agents;
	while(current_xmachine_Generator_holder)
	{
		temp_xmachine_Generator_holder = current_xmachine_Generator_holder->next;
		free_Generator_agent(current_xmachine_Generator_holder, Generator_01_state);
		current_xmachine_Generator_holder = temp_xmachine_Generator_holder;
	}
	current_xmachine_Generator_holder = Generator_00_state->agents;
	while(current_xmachine_Generator_holder)
	{
		temp_xmachine_Generator_holder = current_xmachine_Generator_holder->next;
		free_Generator_agent(current_xmachine_Generator_holder, Generator_00_state);
		current_xmachine_Generator_holder = temp_xmachine_Generator_holder;
	}
}

void free_Generator_states()
{
	free(Generator_01_state);
	free(Generator_00_state);
}

void transition_Generator_agent(xmachine_memory_Generator_holder * tmp, xmachine_memory_Generator_state * from_state, xmachine_memory_Generator_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_Generator_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Generator_agent_internal(xmachine_memory_Generator * agent, xmachine_memory_Generator_state * state)
{
	xmachine_memory_Generator_holder * current = (xmachine_memory_Generator_holder *)malloc(sizeof(xmachine_memory_Generator_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_Generator_agent(int memoryID)
 * \brief Add Generator X-machine to the current being used X-machine list.
 * \param memoryID Variable for the X-machine memory.
 */
void add_Generator_agent(int memoryID)
{
	xmachine_memory_Generator * current;

	current = init_Generator_agent();
	add_Generator_agent_internal(current, current_xmachine_Generator_next_state);

	current->memoryID = memoryID;
}

xmachine_memory_FoodGenerator_state * init_FoodGenerator_state()
{
	xmachine_memory_FoodGenerator_state * current = (xmachine_memory_FoodGenerator_state *)malloc(sizeof(xmachine_memory_FoodGenerator_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_FoodGenerator * init_FoodGenerator_agent()
{
	xmachine_memory_FoodGenerator * current = (xmachine_memory_FoodGenerator *)malloc(sizeof(xmachine_memory_FoodGenerator));
	CHECK_POINTER(current);

	current->memoryFoodID = 0;

	return current;
}

void free_FoodGenerator_agent(xmachine_memory_FoodGenerator_holder * tmp, xmachine_memory_FoodGenerator_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_FoodGenerator_agent()
{
	current_xmachine_FoodGenerator = (xmachine_memory_FoodGenerator *)malloc(sizeof(xmachine_memory_FoodGenerator));
	CHECK_POINTER(current);

		current_xmachine_FoodGenerator->memoryFoodID = 0;
	
}

void unittest_free_FoodGenerator_agent()
{
	
	free(current_xmachine_FoodGenerator);
}

void free_FoodGenerator_agents()
{
	current_xmachine_FoodGenerator_holder = FoodGenerator_01_state->agents;
	while(current_xmachine_FoodGenerator_holder)
	{
		temp_xmachine_FoodGenerator_holder = current_xmachine_FoodGenerator_holder->next;
		free_FoodGenerator_agent(current_xmachine_FoodGenerator_holder, FoodGenerator_01_state);
		current_xmachine_FoodGenerator_holder = temp_xmachine_FoodGenerator_holder;
	}
	current_xmachine_FoodGenerator_holder = FoodGenerator_00_state->agents;
	while(current_xmachine_FoodGenerator_holder)
	{
		temp_xmachine_FoodGenerator_holder = current_xmachine_FoodGenerator_holder->next;
		free_FoodGenerator_agent(current_xmachine_FoodGenerator_holder, FoodGenerator_00_state);
		current_xmachine_FoodGenerator_holder = temp_xmachine_FoodGenerator_holder;
	}
}

void free_FoodGenerator_states()
{
	free(FoodGenerator_01_state);
	free(FoodGenerator_00_state);
}

void transition_FoodGenerator_agent(xmachine_memory_FoodGenerator_holder * tmp, xmachine_memory_FoodGenerator_state * from_state, xmachine_memory_FoodGenerator_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_FoodGenerator_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_FoodGenerator_agent_internal(xmachine_memory_FoodGenerator * agent, xmachine_memory_FoodGenerator_state * state)
{
	xmachine_memory_FoodGenerator_holder * current = (xmachine_memory_FoodGenerator_holder *)malloc(sizeof(xmachine_memory_FoodGenerator_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_FoodGenerator_agent(int memoryFoodID)
 * \brief Add FoodGenerator X-machine to the current being used X-machine list.
 * \param memoryFoodID Variable for the X-machine memory.
 */
void add_FoodGenerator_agent(int memoryFoodID)
{
	xmachine_memory_FoodGenerator * current;

	current = init_FoodGenerator_agent();
	add_FoodGenerator_agent_internal(current, current_xmachine_FoodGenerator_next_state);

	current->memoryFoodID = memoryFoodID;
}

xmachine_memory_Nest_state * init_Nest_state()
{
	xmachine_memory_Nest_state * current = (xmachine_memory_Nest_state *)malloc(sizeof(xmachine_memory_Nest_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_Nest * init_Nest_agent()
{
	xmachine_memory_Nest * current = (xmachine_memory_Nest *)malloc(sizeof(xmachine_memory_Nest));
	CHECK_POINTER(current);

	current->nestX = 0.0;
	current->nestY = 0.0;
	current->nestRadius = 0.0;

	return current;
}

void free_Nest_agent(xmachine_memory_Nest_holder * tmp, xmachine_memory_Nest_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_Nest_agent()
{
	current_xmachine_Nest = (xmachine_memory_Nest *)malloc(sizeof(xmachine_memory_Nest));
	CHECK_POINTER(current);

		current_xmachine_Nest->nestX = 0.0;
		current_xmachine_Nest->nestY = 0.0;
		current_xmachine_Nest->nestRadius = 0.0;
	
}

void unittest_free_Nest_agent()
{
	
	free(current_xmachine_Nest);
}

void free_Nest_agents()
{
	current_xmachine_Nest_holder = Nest_01_state->agents;
	while(current_xmachine_Nest_holder)
	{
		temp_xmachine_Nest_holder = current_xmachine_Nest_holder->next;
		free_Nest_agent(current_xmachine_Nest_holder, Nest_01_state);
		current_xmachine_Nest_holder = temp_xmachine_Nest_holder;
	}
	current_xmachine_Nest_holder = Nest_00_state->agents;
	while(current_xmachine_Nest_holder)
	{
		temp_xmachine_Nest_holder = current_xmachine_Nest_holder->next;
		free_Nest_agent(current_xmachine_Nest_holder, Nest_00_state);
		current_xmachine_Nest_holder = temp_xmachine_Nest_holder;
	}
}

void free_Nest_states()
{
	free(Nest_01_state);
	free(Nest_00_state);
}

void transition_Nest_agent(xmachine_memory_Nest_holder * tmp, xmachine_memory_Nest_state * from_state, xmachine_memory_Nest_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_Nest_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Nest_agent_internal(xmachine_memory_Nest * agent, xmachine_memory_Nest_state * state)
{
	xmachine_memory_Nest_holder * current = (xmachine_memory_Nest_holder *)malloc(sizeof(xmachine_memory_Nest_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_Nest_agent(double nestX, double nestY, double nestRadius)
 * \brief Add Nest X-machine to the current being used X-machine list.
 * \param nestX Variable for the X-machine memory.
 * \param nestY Variable for the X-machine memory.
 * \param nestRadius Variable for the X-machine memory.
 */
void add_Nest_agent(double nestX, double nestY, double nestRadius)
{
	xmachine_memory_Nest * current;

	current = init_Nest_agent();
	add_Nest_agent_internal(current, current_xmachine_Nest_next_state);

	current->nestX = nestX;
	current->nestY = nestY;
	current->nestRadius = nestRadius;
}

xmachine_memory_Food_state * init_Food_state()
{
	xmachine_memory_Food_state * current = (xmachine_memory_Food_state *)malloc(sizeof(xmachine_memory_Food_state));
	CHECK_POINTER(current);

	current->agents = NULL;
	current->count = 0;

	return current;
}

xmachine_memory_Food * init_Food_agent()
{
	xmachine_memory_Food * current = (xmachine_memory_Food *)malloc(sizeof(xmachine_memory_Food));
	CHECK_POINTER(current);

	current->foodID = 0;
	current->size = 0.0;
	current->foodX = 0.0;
	current->foodY = 0.0;
	current->radius = 0.0;
	current->concentration = 0.0;

	return current;
}

void free_Food_agent(xmachine_memory_Food_holder * tmp, xmachine_memory_Food_state * state)
{
	if(tmp->prev == NULL) state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	

	free(tmp->agent);
	free(tmp);
}

void unittest_init_Food_agent()
{
	current_xmachine_Food = (xmachine_memory_Food *)malloc(sizeof(xmachine_memory_Food));
	CHECK_POINTER(current);

		current_xmachine_Food->foodID = 0;
		current_xmachine_Food->size = 0.0;
		current_xmachine_Food->foodX = 0.0;
		current_xmachine_Food->foodY = 0.0;
		current_xmachine_Food->radius = 0.0;
		current_xmachine_Food->concentration = 0.0;
	
}

void unittest_free_Food_agent()
{
	
	free(current_xmachine_Food);
}

void free_Food_agents()
{
	current_xmachine_Food_holder = Food_02_state->agents;
	while(current_xmachine_Food_holder)
	{
		temp_xmachine_Food_holder = current_xmachine_Food_holder->next;
		free_Food_agent(current_xmachine_Food_holder, Food_02_state);
		current_xmachine_Food_holder = temp_xmachine_Food_holder;
	}
	current_xmachine_Food_holder = Food_01_state->agents;
	while(current_xmachine_Food_holder)
	{
		temp_xmachine_Food_holder = current_xmachine_Food_holder->next;
		free_Food_agent(current_xmachine_Food_holder, Food_01_state);
		current_xmachine_Food_holder = temp_xmachine_Food_holder;
	}
	current_xmachine_Food_holder = Food_00_state->agents;
	while(current_xmachine_Food_holder)
	{
		temp_xmachine_Food_holder = current_xmachine_Food_holder->next;
		free_Food_agent(current_xmachine_Food_holder, Food_00_state);
		current_xmachine_Food_holder = temp_xmachine_Food_holder;
	}
}

void free_Food_states()
{
	free(Food_02_state);
	free(Food_01_state);
	free(Food_00_state);
}

void transition_Food_agent(xmachine_memory_Food_holder * tmp, xmachine_memory_Food_state * from_state, xmachine_memory_Food_state * to_state)
{
	if(tmp->prev == NULL) from_state->agents = tmp->next;
	else tmp->prev->next = tmp->next;
	if(tmp->next != NULL) tmp->next->prev = tmp->prev;

	add_Food_agent_internal(tmp->agent, to_state);
	free(tmp);
}

void add_Food_agent_internal(xmachine_memory_Food * agent, xmachine_memory_Food_state * state)
{
	xmachine_memory_Food_holder * current = (xmachine_memory_Food_holder *)malloc(sizeof(xmachine_memory_Food_holder));
	CHECK_POINTER(current);

	current->next = state->agents;
	current->prev = NULL;
	state->agents = current;
	if(current->next != NULL) current->next->prev = current;
	current->agent = agent;

	state->count++;

}

/** \fn void add_Food_agent(int foodID, double size, double foodX, double foodY, double radius, double concentration)
 * \brief Add Food X-machine to the current being used X-machine list.
 * \param foodID Variable for the X-machine memory.
 * \param size Variable for the X-machine memory.
 * \param foodX Variable for the X-machine memory.
 * \param foodY Variable for the X-machine memory.
 * \param radius Variable for the X-machine memory.
 * \param concentration Variable for the X-machine memory.
 */
void add_Food_agent(int foodID, double size, double foodX, double foodY, double radius, double concentration)
{
	xmachine_memory_Food * current;

	current = init_Food_agent();
	add_Food_agent_internal(current, current_xmachine_Food_next_state);

	current->foodID = foodID;
	current->size = size;
	current->foodX = foodX;
	current->foodY = foodY;
	current->radius = radius;
	current->concentration = concentration;
}


/* freexmachines */
/** \fn void freexmachines()
 * \brief Free the currently being used X-machine list.
 */
void freexmachines()
{
	free_Ant_agents();
	free_Pheromone_agents();
	free_Generator_agents();
	free_FoodGenerator_agents();
	free_Nest_agents();
	free_Food_agents();
	
}


/** \fn void set_antID(int antID)
 * \brief Set antID memory variable for current X-machine.
 * \param antID New value for variable.
 */
void set_antID(int antID)
{
	if(current_xmachine->xmachine_Ant) (*current_xmachine->xmachine_Ant).antID = antID;
}

/** \fn int get_antID()
 * \brief Get antID memory variable from current X-machine.
 * \return Value for variable.
 */
int get_antID()
{
	if(current_xmachine->xmachine_Ant) return (*current_xmachine->xmachine_Ant).antID;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_antX(double antX)
 * \brief Set antX memory variable for current X-machine.
 * \param antX New value for variable.
 */
void set_antX(double antX)
{
	if(current_xmachine->xmachine_Ant) (*current_xmachine->xmachine_Ant).antX = antX;
}

/** \fn double get_antX()
 * \brief Get antX memory variable from current X-machine.
 * \return Value for variable.
 */
double get_antX()
{
	if(current_xmachine->xmachine_Ant) return (*current_xmachine->xmachine_Ant).antX;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_antY(double antY)
 * \brief Set antY memory variable for current X-machine.
 * \param antY New value for variable.
 */
void set_antY(double antY)
{
	if(current_xmachine->xmachine_Ant) (*current_xmachine->xmachine_Ant).antY = antY;
}

/** \fn double get_antY()
 * \brief Get antY memory variable from current X-machine.
 * \return Value for variable.
 */
double get_antY()
{
	if(current_xmachine->xmachine_Ant) return (*current_xmachine->xmachine_Ant).antY;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_foodLevel(double foodLevel)
 * \brief Set foodLevel memory variable for current X-machine.
 * \param foodLevel New value for variable.
 */
void set_foodLevel(double foodLevel)
{
	if(current_xmachine->xmachine_Ant) (*current_xmachine->xmachine_Ant).foodLevel = foodLevel;
}

/** \fn double get_foodLevel()
 * \brief Get foodLevel memory variable from current X-machine.
 * \return Value for variable.
 */
double get_foodLevel()
{
	if(current_xmachine->xmachine_Ant) return (*current_xmachine->xmachine_Ant).foodLevel;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_isFed(int isFed)
 * \brief Set isFed memory variable for current X-machine.
 * \param isFed New value for variable.
 */
void set_isFed(int isFed)
{
	if(current_xmachine->xmachine_Ant) (*current_xmachine->xmachine_Ant).isFed = isFed;
}

/** \fn int get_isFed()
 * \brief Get isFed memory variable from current X-machine.
 * \return Value for variable.
 */
int get_isFed()
{
	if(current_xmachine->xmachine_Ant) return (*current_xmachine->xmachine_Ant).isFed;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_isInNest(int isInNest)
 * \brief Set isInNest memory variable for current X-machine.
 * \param isInNest New value for variable.
 */
void set_isInNest(int isInNest)
{
	if(current_xmachine->xmachine_Ant) (*current_xmachine->xmachine_Ant).isInNest = isInNest;
}

/** \fn int get_isInNest()
 * \brief Get isInNest memory variable from current X-machine.
 * \return Value for variable.
 */
int get_isInNest()
{
	if(current_xmachine->xmachine_Ant) return (*current_xmachine->xmachine_Ant).isInNest;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_antDirection(int antDirection)
 * \brief Set antDirection memory variable for current X-machine.
 * \param antDirection New value for variable.
 */
void set_antDirection(int antDirection)
{
	if(current_xmachine->xmachine_Ant) (*current_xmachine->xmachine_Ant).antDirection = antDirection;
}

/** \fn int get_antDirection()
 * \brief Get antDirection memory variable from current X-machine.
 * \return Value for variable.
 */
int get_antDirection()
{
	if(current_xmachine->xmachine_Ant) return (*current_xmachine->xmachine_Ant).antDirection;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_state(int state)
 * \brief Set state memory variable for current X-machine.
 * \param state New value for variable.
 */
void set_state(int state)
{
	if(current_xmachine->xmachine_Ant) (*current_xmachine->xmachine_Ant).state = state;
}

/** \fn int get_state()
 * \brief Get state memory variable from current X-machine.
 * \return Value for variable.
 */
int get_state()
{
	if(current_xmachine->xmachine_Ant) return (*current_xmachine->xmachine_Ant).state;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_lastFoodConc(double lastFoodConc)
 * \brief Set lastFoodConc memory variable for current X-machine.
 * \param lastFoodConc New value for variable.
 */
void set_lastFoodConc(double lastFoodConc)
{
	if(current_xmachine->xmachine_Ant) (*current_xmachine->xmachine_Ant).lastFoodConc = lastFoodConc;
}

/** \fn double get_lastFoodConc()
 * \brief Get lastFoodConc memory variable from current X-machine.
 * \return Value for variable.
 */
double get_lastFoodConc()
{
	if(current_xmachine->xmachine_Ant) return (*current_xmachine->xmachine_Ant).lastFoodConc;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_pheromoneID(int pheromoneID)
 * \brief Set pheromoneID memory variable for current X-machine.
 * \param pheromoneID New value for variable.
 */
void set_pheromoneID(int pheromoneID)
{
	if(current_xmachine->xmachine_Pheromone) (*current_xmachine->xmachine_Pheromone).pheromoneID = pheromoneID;
}

/** \fn int get_pheromoneID()
 * \brief Get pheromoneID memory variable from current X-machine.
 * \return Value for variable.
 */
int get_pheromoneID()
{
	if(current_xmachine->xmachine_Pheromone) return (*current_xmachine->xmachine_Pheromone).pheromoneID;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_life(double life)
 * \brief Set life memory variable for current X-machine.
 * \param life New value for variable.
 */
void set_life(double life)
{
	if(current_xmachine->xmachine_Pheromone) (*current_xmachine->xmachine_Pheromone).life = life;
}

/** \fn double get_life()
 * \brief Get life memory variable from current X-machine.
 * \return Value for variable.
 */
double get_life()
{
	if(current_xmachine->xmachine_Pheromone) return (*current_xmachine->xmachine_Pheromone).life;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_pheromoneX(double pheromoneX)
 * \brief Set pheromoneX memory variable for current X-machine.
 * \param pheromoneX New value for variable.
 */
void set_pheromoneX(double pheromoneX)
{
	if(current_xmachine->xmachine_Pheromone) (*current_xmachine->xmachine_Pheromone).pheromoneX = pheromoneX;
}

/** \fn double get_pheromoneX()
 * \brief Get pheromoneX memory variable from current X-machine.
 * \return Value for variable.
 */
double get_pheromoneX()
{
	if(current_xmachine->xmachine_Pheromone) return (*current_xmachine->xmachine_Pheromone).pheromoneX;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_pheromoneY(double pheromoneY)
 * \brief Set pheromoneY memory variable for current X-machine.
 * \param pheromoneY New value for variable.
 */
void set_pheromoneY(double pheromoneY)
{
	if(current_xmachine->xmachine_Pheromone) (*current_xmachine->xmachine_Pheromone).pheromoneY = pheromoneY;
}

/** \fn double get_pheromoneY()
 * \brief Get pheromoneY memory variable from current X-machine.
 * \return Value for variable.
 */
double get_pheromoneY()
{
	if(current_xmachine->xmachine_Pheromone) return (*current_xmachine->xmachine_Pheromone).pheromoneY;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_memoryID(int memoryID)
 * \brief Set memoryID memory variable for current X-machine.
 * \param memoryID New value for variable.
 */
void set_memoryID(int memoryID)
{
	if(current_xmachine->xmachine_Generator) (*current_xmachine->xmachine_Generator).memoryID = memoryID;
}

/** \fn int get_memoryID()
 * \brief Get memoryID memory variable from current X-machine.
 * \return Value for variable.
 */
int get_memoryID()
{
	if(current_xmachine->xmachine_Generator) return (*current_xmachine->xmachine_Generator).memoryID;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_memoryFoodID(int memoryFoodID)
 * \brief Set memoryFoodID memory variable for current X-machine.
 * \param memoryFoodID New value for variable.
 */
void set_memoryFoodID(int memoryFoodID)
{
	if(current_xmachine->xmachine_FoodGenerator) (*current_xmachine->xmachine_FoodGenerator).memoryFoodID = memoryFoodID;
}

/** \fn int get_memoryFoodID()
 * \brief Get memoryFoodID memory variable from current X-machine.
 * \return Value for variable.
 */
int get_memoryFoodID()
{
	if(current_xmachine->xmachine_FoodGenerator) return (*current_xmachine->xmachine_FoodGenerator).memoryFoodID;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_nestX(double nestX)
 * \brief Set nestX memory variable for current X-machine.
 * \param nestX New value for variable.
 */
void set_nestX(double nestX)
{
	if(current_xmachine->xmachine_Nest) (*current_xmachine->xmachine_Nest).nestX = nestX;
}

/** \fn double get_nestX()
 * \brief Get nestX memory variable from current X-machine.
 * \return Value for variable.
 */
double get_nestX()
{
	if(current_xmachine->xmachine_Nest) return (*current_xmachine->xmachine_Nest).nestX;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_nestY(double nestY)
 * \brief Set nestY memory variable for current X-machine.
 * \param nestY New value for variable.
 */
void set_nestY(double nestY)
{
	if(current_xmachine->xmachine_Nest) (*current_xmachine->xmachine_Nest).nestY = nestY;
}

/** \fn double get_nestY()
 * \brief Get nestY memory variable from current X-machine.
 * \return Value for variable.
 */
double get_nestY()
{
	if(current_xmachine->xmachine_Nest) return (*current_xmachine->xmachine_Nest).nestY;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_nestRadius(double nestRadius)
 * \brief Set nestRadius memory variable for current X-machine.
 * \param nestRadius New value for variable.
 */
void set_nestRadius(double nestRadius)
{
	if(current_xmachine->xmachine_Nest) (*current_xmachine->xmachine_Nest).nestRadius = nestRadius;
}

/** \fn double get_nestRadius()
 * \brief Get nestRadius memory variable from current X-machine.
 * \return Value for variable.
 */
double get_nestRadius()
{
	if(current_xmachine->xmachine_Nest) return (*current_xmachine->xmachine_Nest).nestRadius;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_foodID(int foodID)
 * \brief Set foodID memory variable for current X-machine.
 * \param foodID New value for variable.
 */
void set_foodID(int foodID)
{
	if(current_xmachine->xmachine_Food) (*current_xmachine->xmachine_Food).foodID = foodID;
}

/** \fn int get_foodID()
 * \brief Get foodID memory variable from current X-machine.
 * \return Value for variable.
 */
int get_foodID()
{
	if(current_xmachine->xmachine_Food) return (*current_xmachine->xmachine_Food).foodID;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (int)0;
}

/** \fn void set_size(double size)
 * \brief Set size memory variable for current X-machine.
 * \param size New value for variable.
 */
void set_size(double size)
{
	if(current_xmachine->xmachine_Food) (*current_xmachine->xmachine_Food).size = size;
}

/** \fn double get_size()
 * \brief Get size memory variable from current X-machine.
 * \return Value for variable.
 */
double get_size()
{
	if(current_xmachine->xmachine_Food) return (*current_xmachine->xmachine_Food).size;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_foodX(double foodX)
 * \brief Set foodX memory variable for current X-machine.
 * \param foodX New value for variable.
 */
void set_foodX(double foodX)
{
	if(current_xmachine->xmachine_Food) (*current_xmachine->xmachine_Food).foodX = foodX;
}

/** \fn double get_foodX()
 * \brief Get foodX memory variable from current X-machine.
 * \return Value for variable.
 */
double get_foodX()
{
	if(current_xmachine->xmachine_Food) return (*current_xmachine->xmachine_Food).foodX;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_foodY(double foodY)
 * \brief Set foodY memory variable for current X-machine.
 * \param foodY New value for variable.
 */
void set_foodY(double foodY)
{
	if(current_xmachine->xmachine_Food) (*current_xmachine->xmachine_Food).foodY = foodY;
}

/** \fn double get_foodY()
 * \brief Get foodY memory variable from current X-machine.
 * \return Value for variable.
 */
double get_foodY()
{
	if(current_xmachine->xmachine_Food) return (*current_xmachine->xmachine_Food).foodY;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_radius(double radius)
 * \brief Set radius memory variable for current X-machine.
 * \param radius New value for variable.
 */
void set_radius(double radius)
{
	if(current_xmachine->xmachine_Food) (*current_xmachine->xmachine_Food).radius = radius;
}

/** \fn double get_radius()
 * \brief Get radius memory variable from current X-machine.
 * \return Value for variable.
 */
double get_radius()
{
	if(current_xmachine->xmachine_Food) return (*current_xmachine->xmachine_Food).radius;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}

/** \fn void set_concentration(double concentration)
 * \brief Set concentration memory variable for current X-machine.
 * \param concentration New value for variable.
 */
void set_concentration(double concentration)
{
	if(current_xmachine->xmachine_Food) (*current_xmachine->xmachine_Food).concentration = concentration;
}

/** \fn double get_concentration()
 * \brief Get concentration memory variable from current X-machine.
 * \return Value for variable.
 */
double get_concentration()
{
	if(current_xmachine->xmachine_Food) return (*current_xmachine->xmachine_Food).concentration;

    // suppress compiler warning by returning dummy value /
    // this statement should rightfully NEVER be reached /
    return (double)0;
}


/** \fn double agent_get_range()
 * \brief Fixed routine to get the range from current X-machine
  * \return Value of range
  */
double agent_get_range()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Ant) value = current_xmachine->xmachine_Ant->;*/
    /*if (current_xmachine->xmachine_Pheromone) value = current_xmachine->xmachine_Pheromone->;*/
    /*if (current_xmachine->xmachine_Generator) value = current_xmachine->xmachine_Generator->;*/
    /*if (current_xmachine->xmachine_FoodGenerator) value = current_xmachine->xmachine_FoodGenerator->;*/
    /*if (current_xmachine->xmachine_Nest) value = current_xmachine->xmachine_Nest->;*/
    /*if (current_xmachine->xmachine_Food) value = current_xmachine->xmachine_Food->radius;*/

    return value;
}

/** \fn int agent_get_id()
 * \brief Fixed routine to get the id for the current X-machine
  * \return Value of agent id
  */
int agent_get_id()
{
    int value = 0;
    /*if (current_xmachine->xmachine_Ant) value = current_xmachine->xmachine_Ant->;*/
    /*if (current_xmachine->xmachine_Pheromone) value = current_xmachine->xmachine_Pheromone->;*/
    /*if (current_xmachine->xmachine_Generator) value = current_xmachine->xmachine_Generator->;*/
    /*if (current_xmachine->xmachine_FoodGenerator) value = current_xmachine->xmachine_FoodGenerator->;*/
    /*if (current_xmachine->xmachine_Nest) value = current_xmachine->xmachine_Nest->;*/
    /*if (current_xmachine->xmachine_Food) value = current_xmachine->xmachine_Food->;*/

    return value;
}

/** \fn double agent_get_x()
 * \brief Fixed routine to get the x coordinate from current X-machine
  * \return Value of x coordinate
  */
double agent_get_x()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Ant) value = current_xmachine->xmachine_Ant->0.0;*/
    /*if (current_xmachine->xmachine_Pheromone) value = current_xmachine->xmachine_Pheromone->0.0;*/
    /*if (current_xmachine->xmachine_Generator) value = current_xmachine->xmachine_Generator->0.0;*/
    /*if (current_xmachine->xmachine_FoodGenerator) value = current_xmachine->xmachine_FoodGenerator->0.0;*/
    /*if (current_xmachine->xmachine_Nest) value = current_xmachine->xmachine_Nest->0.0;*/
    /*if (current_xmachine->xmachine_Food) value = current_xmachine->xmachine_Food->0.0;*/

    return value;
}
/** \fn double agent_get_y()
 * \brief Fixed routine to get the y coordinate from current X-machine
  * \return Value of y coordinate
  */
double agent_get_y()
{
    double value = 0.0;
    /*if (current_xmachine->xmachine_Ant) value = current_xmachine->xmachine_Ant->0.0;*/
    /*if (current_xmachine->xmachine_Pheromone) value = current_xmachine->xmachine_Pheromone->0.0;*/
    /*if (current_xmachine->xmachine_Generator) value = current_xmachine->xmachine_Generator->0.0;*/
    /*if (current_xmachine->xmachine_FoodGenerator) value = current_xmachine->xmachine_FoodGenerator->0.0;*/
    /*if (current_xmachine->xmachine_Nest) value = current_xmachine->xmachine_Nest->0.0;*/
    /*if (current_xmachine->xmachine_Food) value = current_xmachine->xmachine_Food->0.0;*/

    return value;
}
/** \fn double agent_get_z()
 * \brief Fixed routine to get the z coordinate from current X-machine
  * \return Value of z coordinate
  */
double agent_get_z()
{
    double value = 0.0;

    return value;
}

/** \fn void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
 * \brief Add a node to the node list.
 * \param node_id The node ID.
 * \param minx The minumum value on the x-axis of the bounding volume.
 * \param maxx The maximum value on the x-axis of the bounding volume.
 * \param miny The minumum value on the y-axis of the bounding volume.
 * \param maxy The maximum value on the y-axis of the bounding volume.
 * \param minz The minumum value on the z-axis of the bounding volume.
 * \param maxz The maximum value on the z-axis of the bounding volume.
 */
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz)
{
	node_information * current = *p_node_info;
	node_information * tmp = NULL;

	while(current)
	{
		tmp = current;
		current = current->next;
	}

	current = (node_information *)malloc(sizeof(node_information));
		CHECK_POINTER(current);

	if(tmp)
	{
		tmp->next = current;
	}
	else
	{
		*p_node_info = current;
	}

	current->next = NULL;
	current->node_id = node_id;
	current->agents_in_halo = 0;
	current->agent_total = 0;
	current->agents = NULL;
	current->pheromoneInformation_messages = NULL;
	current->newPheromoneInput_messages = NULL;
	current->foodInformation_messages = NULL;
	current->foodEaten_messages = NULL;
	current->newFood_messages = NULL;
	current->pheromoneIncreased_messages = NULL;
	current->nestInformation_messages = NULL;


	current->partition_data[0] = minx;
	current->partition_data[1] = maxx;
	current->partition_data[2] = miny;
	current->partition_data[3] = maxy;
	current->partition_data[4] = minz;
	current->partition_data[5] = maxz;
}

/**\fn void free_node_info()
 * \brief Free the node list.
 */
void free_node_info()
{
	node_information * tmp, * head;
	head = *p_node_info;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}

	*p_node_info = NULL;
}

/** \fn void clean_up(int code)
 * \brief Add a node to the node list.
 * \param code The error code (zero is no error).
 */
void clean_up(int code)
{
    int rc;
	FILE *file;
	char data[100];

	free(current_xmachine);
	/* Free x-machine memory */
	freexmachines();
	/* Free space partitions linked list */
	free_node_info();
	/* Free output list */
	free_FLAME_outputs(&FLAME_outputs);
	/* Free agent states */
	free_Ant_states();
	free_Pheromone_states();
	free_Generator_states();
	free_FoodGenerator_states();
	free_Nest_states();
	free_Food_states();


	/* Free message boards */

	rc = MB_Delete(&b_pheromoneInformation);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'pheromoneInformation' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pheromoneInformation' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pheromoneInformation' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_newPheromoneInput);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'newPheromoneInput' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'newPheromoneInput' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'newPheromoneInput' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_foodInformation);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'foodInformation' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foodInformation' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'foodInformation' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_foodEaten);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'foodEaten' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foodEaten' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'foodEaten' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_newFood);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'newFood' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'newFood' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'newFood' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_pheromoneIncreased);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'pheromoneIncreased' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pheromoneIncreased' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pheromoneIncreased' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif

	rc = MB_Delete(&b_nestInformation);
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not delete 'nestInformation' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'nestInformation' board has not been created?\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'nestInformation' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_Delete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif


    rc = MB_Env_Finalise();
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not finalise MB environment\n");
       switch(rc) {
           case MB_ERR_ENV:
               fprintf(stderr, "\t reason: MB environment not yet started?\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Env_Finalise returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }

	       
       	   exit(rc);
    }
    #endif



	/* Write log file */
	sprintf(data, "%slog.xml", outputpath);
	file = fopen(data, "a");
	fputs("<totaltime>", file);
	sprintf(data, "%d", (int)(total_time * 1000.0) % 1000);
	fputs(data, file);
	fputs("</totaltime>\n", file);
	/*fputs("<totalmessages>", file);
	sprintf(data, "%i", total_messages);
	fputs(data, file);
	fputs("</totalmessages>", file);*/
	fputs("</model_run>", file);
	fclose(file);


	if(code != 0)
	{
		printf("*** Error: ");
		if(code == 100) printf("cannot handle specified number of space partitions");
		if(code == 101) printf("could not find number of space partitions config in file");

		printf(" ***");
		exit(0);
	}
}


/** \fn void propagate_agents()
 * \brief Check agent positions to see if any need to be moved to a another node.
 */
void propagate_agents()
{
/*	node_information * node_info;
	xmachine * before_xmachine, * temp_xmachine;
	xmachine ** p_temp_xmachine;
	double x_xmachine, y_xmachine, z_xmachine;
	current_xmachine = *p_xmachine;
	before_xmachine = NULL;
	while(current_xmachine)
	{
		if(current_xmachine->xmachine_Ant != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Ant->0.0;
			y_xmachine = current_xmachine->xmachine_Ant->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Pheromone != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Pheromone->0.0;
			y_xmachine = current_xmachine->xmachine_Pheromone->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Generator != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Generator->0.0;
			y_xmachine = current_xmachine->xmachine_Generator->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_FoodGenerator != NULL)
		{
			x_xmachine = current_xmachine->xmachine_FoodGenerator->0.0;
			y_xmachine = current_xmachine->xmachine_FoodGenerator->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Nest != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Nest->0.0;
			y_xmachine = current_xmachine->xmachine_Nest->0.0;
			z_xmachine = 0.0;
		}
		else if(current_xmachine->xmachine_Food != NULL)
		{
			x_xmachine = current_xmachine->xmachine_Food->0.0;
			y_xmachine = current_xmachine->xmachine_Food->0.0;
			z_xmachine = 0.0;
		}

		if(x_xmachine < current_node->partition_data[0] ||
		   x_xmachine > current_node->partition_data[1] ||
		   y_xmachine < current_node->partition_data[2] ||
		   y_xmachine > current_node->partition_data[3] ||
		   z_xmachine < current_node->partition_data[4] ||
		   z_xmachine > current_node->partition_data[5])
		{
			node_info = *p_node_info;
			while(node_info)
			{
				if(node_info->node_id != current_node->node_id &&
				node_info->partition_data[0] < x_xmachine && node_info->partition_data[1] > x_xmachine &&
				node_info->partition_data[2] < y_xmachine && node_info->partition_data[3] > y_xmachine &&
				node_info->partition_data[4] < z_xmachine && node_info->partition_data[5] > z_xmachine)
				{
                    // Remove agent
                    if(before_xmachine) before_xmachine->next = current_xmachine->next;
                    else *p_xmachine = current_xmachine->next;
                    current_node->agent_total--;
                    // Add agent
                    p_temp_xmachine = &node_info->agents;
                    temp_xmachine = *p_temp_xmachine;
                    current_xmachine->next = temp_xmachine;
                    *p_temp_xmachine = current_xmachine;
                    node_info->agent_total++;
                    node_info = NULL;
				}
				else node_info = node_info->next;
				}
			}
			else before_xmachine = current_xmachine;

			if(before_xmachine) current_xmachine = before_xmachine->next;
			else current_xmachine = NULL;
		}*/
}


/** \fn int_array * init_int_array()
 * \brief Allocate memory for a dynamic integer array.
 * \return int_array Pointer to the new dynamic integer array.
 */
void init_int_array(int_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (int *)malloc(ARRAY_BLOCK_SIZE * sizeof(int));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_int_array(int_array * array)
* \brief Reset the int array to hold nothing.
* \param array Pointer to the dynamic integer array.
*/
void reset_int_array(int_array * array)
{
	(*array).size = 0;
}

/** \fn void free_int_array(int_array * array)
* \brief Free the memory of a dynamic integer array.
* \param array Pointer to the dynamic integer array.
*/
void free_int_array(int_array * array)
{
	free((*array).array);
}

void copy_int_array(int_array * from, int_array * to)
{
	int i;
	//to = init_int_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_int(to, (*from).array[i]);
	}
}

/** \fn void sort_int_array(int_array * array)
* \brief Sort the elements of a dynamic integer array with smallest first.
* \param array Pointer to the dynamic integer array.
*/
/*void sort_int_array(int_array * array)
{
	int i, j, temp;

	for(i=0; i<((*array).size-1); i++)
	{
		for(j=0; j<((*array).size-1)-i; j++)
		{
			if(*((*array).array+j+1) < *((*array).array+j))
			{
                temp = *((*array).(*array)+j);
                *((*array).array+j) = *((*array).array+j+1);
                *((*array).array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_int(int *array, int elements)
 *  \brief Sorts the elements of the integer array in ascending order.
 *  \param Pointer to integer array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_int(int array, int elements)
{
	#define  LEVEL  1000
	int  pivot, begin[LEVEL], end[LEVEL], i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_int(int_array * array, int new_int)
* \brief Add an integer to the dynamic integer array.
* \param array Pointer to the dynamic integer array.
* \param new_int The integer to add
*/
void add_int(int_array * array, int new_int)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (int *)realloc((*array).array, ((*array).total_size * sizeof(int)));
	}
	(*array).array[(*array).size] = new_int;
	(*array).size++;
}

/** \fn void remove_int(int_array * array, int index)
 * \brief Remove an integer from a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 * \param index The index of the integer to remove.
 */
void remove_int(int_array * array, int index)
{
	int i;

	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_int_array(int_array * array)
 * \brief Print the elements of a dynamic integer array.
 * \param array Pointer to the dynamic integer array.
 */
void print_int_array(int_array * array)
{
	int i;

	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %d", i, (*array).array[i]);
	}
}

/** \fn float_array * init_float_array()
 * \brief Allocate memory for a dynamic float array.
 * \return float_array Pointer to the new dynamic float array.
 */
void init_float_array(float_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (float *)malloc(ARRAY_BLOCK_SIZE * sizeof(float));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_float_array(float_array * array)
* \brief Reset the float array to hold nothing.
* \param array Pointer to the dynamic float array.
*/
void reset_float_array(float_array * array)
{
	(*array).size = 0;
}

/** \fn void free_float_array(float_array * array)
* \brief Free the memory of a dynamic float array.
* \param array Pointer to the dynamic float array.
*/
void free_float_array(float_array * array)
{
	free((*array).array);
}

void copy_float_array(float_array * from, float_array * to)
{
	int i;
	//to = init_float_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_float(to, (*from).array[i]);
	}
}

/** \fn void sort_float_array(float_array * array)
* \brief Sort the elements of a dynamic float array with smallest first.
* \param array Pointer to the dynamic float array.
*/
/*void sort_float_array(float_array array)
{
	int i, j;
	float temp;
	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++)
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j);
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_float(float *array, int elements)
 *  \brief Sorts the elements of the float array in ascending order.
 *  \param Pointer to float array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_float(float array, int elements)
{
	#define  LEVEL  1000
	int i=0, left, right ;
	float pivot, begin[LEVEL], end[LEVEL];
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_float(float_array * array, float new_float)
* \brief Add an floateger to the dynamic float array.
* \param array Pointer to the dynamic float array.
* \param new_float The float to add
*/
void add_float(float_array * array, float new_float)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (float *)realloc((*array).array, ((*array).total_size * sizeof(float)));
	}
	(*array).array[(*array).size] = new_float;
	(*array).size++;
}

/** \fn void remove_float(float_array * array, int index)
 * \brief Remove an floateger from a dynamic float array.
 * \param array Pointer to the dynamic float array.
 * \param index The index of the float to remove.
 */
void remove_float(float_array * array, int index)
{
	int i;

	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_float_array(float_array * array)
 * \brief Print the elements of a dynamic float array.
 * \param array Pointer to the dynamic float array.
 */
void print_float_array(float_array * array)
{
	int i;
	/* printf(""); // compiler does not like empty prfloats */
	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn double_array * init_double_array()
 * \brief Allocate memory for a dynamic double array.
 * \return double_array Pointer to the new dynamic double array.
 */
void init_double_array(double_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (double *)malloc(ARRAY_BLOCK_SIZE * sizeof(double));
	CHECK_POINTER((*array).array);
}

/** \fn void reset_double_array(double_array * array)
* \brief Reset the double array to hold nothing.
* \param array Pointer to the dynamic double array.
*/
void reset_double_array(double_array * array)
{
	(*array).size = 0;
}

/** \fn void free_double_array(double_array * array)
 * \brief Free the memory of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void free_double_array(double_array * array)
{
	free((*array).array);
}

void copy_double_array(double_array * from, double_array * to)
{
	int i;
	//to = init_double_array();

	for (i = 0; i < (*from).size; i++)
	{
		add_double(to, (*from).array[i]);
	}
}

/** \fn void sort_double_array(double_array * array)
 * \brief Sort the elements of a dynamic double array with smallest first.
 * \param array Pointer to the dynamic double array.
 */
/*void sort_double_array(double_array array)
{
	int i, j;
	double temp;

	// Using bubble sorts nested loops //
	for(i=0; i<(array.size-1); i++)
	{
		for(j=0; j<(array.size-1)-i; j++)
		{
			// Comparing the values between neighbours //
			if(*(array.array+j+1) < *(array.array+j))
			{
                // Swap neighbours //
                temp = *(array.array+j);
                *(array.array+j) = *(array.array+j+1);
                *(array.array+j+1) = temp;
			}
		}
	}
}*/

/** \fn int quicksort_double(double *array, int elements)
 *  \brief Sorts the elements of the double array in ascending order.
 *  \param Pointer to double array
 *  \param Number of elements that must be sorted
 *  \return integer value indicating success(0) or failure(1)
 */
/*int quicksort_double(double array, int elements)
{
	#define  LEVEL  1000
	double pivot, begin[LEVEL], end[LEVEL];
	int  i=0, left, right ;
	begin[0]=0; end[0]=elements;
	while (i>=0)
	{
		left=begin[i]; right=end[i]-1;
		if (left<right)
		{
			pivot=array[left]; if (i==LEVEL-1) return 1;
			while (left<right)
			{
				while (array[right]>=pivot && left<right) right--;
				if (left<right) array[left++]=array[right];
				while (array[left]<=pivot && left<right) left++;
				if (left<right) array[right--]=array[left];
			}
			array[left]=pivot;
			begin[i+1]=left+1;
			end[i+1]=end[i];
			end[i++]=left;
		}
	    else
	    {
	      i--;
	    }
	}
	return 0;
}*/

/** \fn void add_double(double_array * array, double new_double)
 * \brief Add an double to the dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param new_double The double to add
 */
void add_double(double_array * array, double new_double)
{
	if((*array).size == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (double *)realloc((*array).array, ((*array).total_size * sizeof(double)));
	}
	(*array).array[(*array).size] = new_double;
	(*array).size++;
}

/** \fn void remove_double(double_array * array, int index)
 * \brief Remove an double from a dynamic double array.
 * \param array Pointer to the dynamic double array.
 * \param index The index of the double to remove.
 */
void remove_double(double_array * array, int index)
{
	int i;
	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn void print_double_array(double_array * array)
 * \brief Print the elements of a dynamic double array.
 * \param array Pointer to the dynamic double array.
 */
void print_double_array(double_array * array)
{
	int i;

	for(i=0; i<(*array).size; i++)
	{
		printf("%d> %f", i, (*array).array[i]);
	}
}

/** \fn char_array * init_char_array()
 * \brief Allocate memory for a dynamic char array.
 * \return char_array Pointer to the new dynamic char array.
 */
void init_char_array(char_array * array)
{
	(*array).size = 0;
	(*array).total_size = ARRAY_BLOCK_SIZE;
	(*array).array = (char *)malloc(ARRAY_BLOCK_SIZE * sizeof(char));
	CHECK_POINTER((*array).array);
	(*array).array[0] = '\0';
}

/** \fn void reset_char_array(char_array * array)
* \brief Reset the char array to hold nothing.
* \param array Pointer to the dynamic char array.
*/
void reset_char_array(char_array * array)
{
	(*array).size = 0;
}

/** \fn void free_char_array(char_array * array)
 * \brief Free the memory of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void free_char_array(char_array * array)
{
	free((*array).array);
}

void copy_char_array(char_array * from, char_array * to)
{
	int i;

	for (i = 0; i < (*from).size; i++)
	{
		add_char(to, (*from).array[i]);
	}
}

/** \fn void add_char(char_array * array, char new_char)
 * \brief Add an char to the dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param new_char The char to add
 */
void add_char(char_array * array, char new_char)
{
	if((*array).size + 1 == (*array).total_size)
	{
		(*array).total_size = (*array).total_size + ARRAY_BLOCK_SIZE;
		(*array).array = (char *)realloc((*array).array, ((*array).total_size * sizeof(char)));
	}
	(*array).array[(*array).size] = new_char;
	(*array).array[(*array).size + 1] = '\0';
	(*array).size++;
}

/** \fn void remove_char(char_array * array, int index)
 * \brief Remove an char from a dynamic char array.
 * \param array Pointer to the dynamic char array.
 * \param index The index of the char to remove.
 */
void remove_char(char_array * array, int index)
{
	int i;
	if(index <= (*array).size)
	{
		/* memcopy?? */
		for(i = index; i < (*array).size - 1; i++)
		{
			(*array).array[i] = (*array).array[i+1];
		}
		(*array).size--;
	}
}

/** \fn char * copy_array_to_str(char_array * array)
 * \brief Return pointer to string from a char_array.
 * \param array Pointer to the dynamic integer array.
 * \return char Pointer to the new string.
 */
char * copy_array_to_str(char_array * array)
{
	char * new_string = (char *)malloc( ((*array).size + 1) * sizeof(char));
	CHECK_POINTER(new_string);
	return strcpy(new_string, (*array).array);
}

/** \fn void print_char_array(char_array * array)
 * \brief Print the elements of a dynamic char array.
 * \param array Pointer to the dynamic char array.
 */
void print_char_array(char_array * array)
{
	printf("%s", (*array).array);
}


/** \fn int idle()
 * \brief an idle function for use by agents.
 */
int idle()
{
	return 0;
}



