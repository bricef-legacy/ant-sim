/**
 * \file  main.c
 * \brief Holds main function of the program.
 */

#include "header.h"

/** \fn int main(int argc, char * argv[])
 * \brief Main program loop.
 * \param argc Argument count.
 * \param argv Pointer Pointer to Argument vector.
 */
int main(int argc, char * argv[])
{
	/* Timing variables */
	double start, stop, interval;
	FILE *file;
	char data[100];
	char logfilepath[1000];
	char inputpath[1000];
	char * c;
	int lastd = 0;
	int i;
	int rc;
	int iteration_number;
	int iteration_total;
	int * p_iteration_number;
	/* For backwards compatabilty allocate current_xmachine */
	current_xmachine = (xmachine *)malloc(sizeof(xmachine));
	CHECK_POINTER(current_xmachine);
	//xmachine_memory_Ant * temp_xmachine_Ant;
	//xmachine_memory_Pheromone * temp_xmachine_Pheromone;
	//xmachine_memory_Generator * temp_xmachine_Generator;
	//xmachine_memory_FoodGenerator * temp_xmachine_FoodGenerator;
	//xmachine_memory_Nest * temp_xmachine_Nest;
	//xmachine_memory_Food * temp_xmachine_Food;

	/* Particle cloud data */
	double cloud_data[6];
	/* Count to debug function branches */
	int FLAME_debug_count;

/* For partition method. Makes geometric (-g flag) the default but may be overridden with -r for round-robin */
	int partition_method=1;



	/* Output frequency is 1 as default */
	output_frequency = 1;
	/* Set random seed */
/*	srand(time(NULL)); */

	

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

	/* Initialise pointers */
	initialise_pointers();
	p_iteration_number = &iteration_number;


	printf("FLAME Application: Pharaoh's Ants Foraging Model \n");


	printf("Debug mode enabled \n");



if(argc < 2)
	{

		printf("Usage: %s <number of iterations> [<states_directory>]/<init_state> <partitions> [-r | -g ]\n",argv[0]);



		exit(0);
	}
	iteration_total = atoi(argv[1]);
printf("Iterations: %i\n", iteration_total);

	/* Read initial states of x-machines */
	if(argc < 3)
	{
		printf("Need two parameters\n");
		exit(0);
	}
	strcpy(inputpath, argv[2]);
/*printf("Initial states: %s\n", inputpath);*/

	i = 0;
	lastd = -1;
	while(inputpath[i] != '\0')
	{
		/* For windows directories */
		if(inputpath[i] == '\\') lastd=i;
		/* For unix directories */
		if(inputpath[i] == '/') lastd=i;
		i++;
	}
	strcpy(outputpath, inputpath);
	outputpath[lastd+1] = '\0';

/*printf("Ouput dir: %s\n", outputpath);*/


	/* Read number of space partitions (1 by default) */
	totalnodes = 1;
	if(argc > 3)
	{
		totalnodes = atoi(argv[3]);
	}


	i = 3;
	while(argc > i)
	{
		if(strcmp(argv[i],"-f") == 0)
		{
			if(argc > (i+1))
			{
				output_offset = 0;
				/* Find offset, separated by the char '+' */
				c = strchr(argv[(i+1)], '+');
				if(c == NULL)
				{
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d\n", output_frequency);
				}
				else
				{
					output_offset = atoi(argv[(i+1)]+(c-argv[(i+1)])+1);
					argv[(i+1)][c-argv[(i+1)]] = 0;
					output_frequency = atoi(argv[(i+1)]);
					printf("Using output frequency of: %d with offset %d\n", output_frequency, output_offset);
				}

				if(output_frequency == 0)
				{
					printf("Output frequency cannot be zero\n");
					exit(0);
				}

				i++;
			}
			else
			{
				printf("Output frequency number not defined\n");
				exit(0);
			}
		}
		/* Partitioning method: -g = geometric, -r = round-robin */
		if(strcmp(argv[i],"-g") == 0) partition_method = 1;
		if(strcmp(argv[i],"-r") == 0) partition_method = 2;
		i++;
	}


	    /* Read initial data into p_xmachine  */

       //agent_list = p_xmachine;
       readinitialstates(inputpath, outputpath, p_iteration_number, cloud_data, partition_method, 0);
       /* Generate partitions */
       generate_partitions(cloud_data,totalnodes,partition_method);
       save_partition_data();






    /* Partition data */
    /* stc: no partitions in serial */
	//partition_data(totalnodes, agent_list, cloud_data, partition_method);



		/*i = 0;
		current_node = *p_node_info;
		while(current_node)
		{
			printf("No of agents on partition %d: %d\n", current_node->node_id, current_node->agent_total);
			i += current_node->agent_total;
			current_node = current_node->next;
		}
		printf("Agent total check: %d\n", i);*/

        /* restore current_node pointer */
		//current_node = *p_node_info;



	/* Start log file (now so that xvisualiser can read straight away) */

	/* Write log file */
	sprintf(logfilepath, "%slog.xml", outputpath);
	file = fopen(logfilepath, "w");
	fputs("<model_run>\n", file);
	fputs("<codetype>", file);
	fputs("serial", file);

	fputs("</codetype>\n", file);
	fputs("<nodes>", file);
	sprintf(data, "%i", totalnodes);
	fputs(data, file);
	fputs("</nodes>\n", file);

	/* print timer into */
	fputs("<!-- <time> unit: milliseconds -->\n", file);

	sprintf(data, "unspecified");
	
	fputs("<!-- <time> timer resolution: ", file);
	fputs(data, file);
	fputs(")-->\n", file);

	start = get_time();
	stop = get_time();
	sprintf(data, "%.2e ms", (stop - start) * 1000.0);
	fputs("<!-- <time> timer overhead: ~", file);
	fputs(data, file);
	fputs(")-->\n", file);


	fclose(file);

	/* Start timing */
	start = get_time();

    /* pre-randomise agents for first iteration */
    //randomisexagent();

	for(iteration_loop=iteration_number+1; iteration_loop < iteration_number+iteration_total+1; iteration_loop++)
	{
		interval = get_time();
		
		/* Print out iteration number */
		fprintf(stdout, "Iteration - %d\n", iteration_loop);
		/* Flush stdout to keep user updated on progress */
		fflush(stdout);
		
		/* START OF ITERATION */

	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start nestInformation\n");
	current_xmachine_Nest_holder = Nest_00_state->agents;
	while(current_xmachine_Nest_holder)
	{
		temp_xmachine_Nest_holder = current_xmachine_Nest_holder->next;
		current_xmachine_Nest = current_xmachine_Nest_holder->agent;
		current_xmachine_Nest_next_state = Nest_01_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Nest = current_xmachine_Nest;

		

		

			i = nestInformation();

		

			if(i == 1)
			{
				free_Nest_agent(current_xmachine_Nest_holder, Nest_00_state);
			}
			else
			{
				transition_Nest_agent(current_xmachine_Nest_holder, Nest_00_state, Nest_01_state);
			}
		

		current_xmachine_Nest = NULL;

		current_xmachine_Nest_holder = temp_xmachine_Nest_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish nestInformation\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_nestInformation)\n");
    rc = MB_SyncStart(b_nestInformation);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_nestInformation)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'nestInformation' board\n");
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start pheromoneInformation\n");
	current_xmachine_Pheromone_holder = Pheromone_00_state->agents;
	while(current_xmachine_Pheromone_holder)
	{
		temp_xmachine_Pheromone_holder = current_xmachine_Pheromone_holder->next;
		current_xmachine_Pheromone = current_xmachine_Pheromone_holder->agent;
		current_xmachine_Pheromone_next_state = Pheromone_01_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Pheromone = current_xmachine_Pheromone;

		

		

			i = pheromoneInformation();

		

			if(i == 1)
			{
				free_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_00_state);
			}
			else
			{
				transition_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_00_state, Pheromone_01_state);
			}
		

		current_xmachine_Pheromone = NULL;

		current_xmachine_Pheromone_holder = temp_xmachine_Pheromone_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish pheromoneInformation\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_pheromoneInformation)\n");
    rc = MB_SyncStart(b_pheromoneInformation);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_pheromoneInformation)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'pheromoneInformation' board\n");
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start foodInformation\n");
	current_xmachine_Food_holder = Food_00_state->agents;
	while(current_xmachine_Food_holder)
	{
		temp_xmachine_Food_holder = current_xmachine_Food_holder->next;
		current_xmachine_Food = current_xmachine_Food_holder->agent;
		current_xmachine_Food_next_state = Food_01_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Food = current_xmachine_Food;

		

		

			i = foodInformation();

		

			if(i == 1)
			{
				free_Food_agent(current_xmachine_Food_holder, Food_00_state);
			}
			else
			{
				transition_Food_agent(current_xmachine_Food_holder, Food_00_state, Food_01_state);
			}
		

		current_xmachine_Food = NULL;

		current_xmachine_Food_holder = temp_xmachine_Food_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish foodInformation\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_foodInformation)\n");
    rc = MB_SyncStart(b_foodInformation);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_foodInformation)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'foodInformation' board\n");
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start updateState\n");
	current_xmachine_Ant_holder = Ant_00_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		current_xmachine_Ant = current_xmachine_Ant_holder->agent;
		current_xmachine_Ant_next_state = Ant_01_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Ant = current_xmachine_Ant;

		

		

			i = updateState();

		

			if(i == 1)
			{
				free_Ant_agent(current_xmachine_Ant_holder, Ant_00_state);
			}
			else
			{
				transition_Ant_agent(current_xmachine_Ant_holder, Ant_00_state, Ant_01_state);
			}
		

		current_xmachine_Ant = NULL;

		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish updateState\n");


	/* DEBUG: States with branching functions */
		current_xmachine_Ant_holder = Ant_01_state->agents;
		while(current_xmachine_Ant_holder)
		{
			FLAME_debug_count = 0;
			/* Function: findNest */
			if(FLAME_condition_Ant_findNest_01_02(current_xmachine_Ant_holder->agent))
			{ FLAME_debug_count++; }
			/* Function: walk */
			if(FLAME_condition_Ant_walk_01_02(current_xmachine_Ant_holder->agent))
			{ FLAME_debug_count++; }
			/* Function: stayInNest */
			if(FLAME_condition_Ant_stayInNest_01_04(current_xmachine_Ant_holder->agent))
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'Ant' leaving state '01'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start decreasePheromoneLife\n");
	current_xmachine_Pheromone_holder = Pheromone_01_state->agents;
	while(current_xmachine_Pheromone_holder)
	{
		temp_xmachine_Pheromone_holder = current_xmachine_Pheromone_holder->next;
		current_xmachine_Pheromone = current_xmachine_Pheromone_holder->agent;
		current_xmachine_Pheromone_next_state = Pheromone_02_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Pheromone = current_xmachine_Pheromone;

		

		

			i = decreasePheromoneLife();

		

			if(i == 1)
			{
				free_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_01_state);
			}
			else
			{
				transition_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_01_state, Pheromone_02_state);
			}
		

		current_xmachine_Pheromone = NULL;

		current_xmachine_Pheromone_holder = temp_xmachine_Pheromone_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish decreasePheromoneLife\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start stayInNest\n");
	current_xmachine_Ant_holder = Ant_01_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		current_xmachine_Ant = current_xmachine_Ant_holder->agent;
		current_xmachine_Ant_next_state = Ant_04_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Ant = current_xmachine_Ant;

		if(FLAME_condition_Ant_stayInNest_01_04(current_xmachine_Ant))
		{

		

			i = stayInNest();

		

			if(i == 1)
			{
				free_Ant_agent(current_xmachine_Ant_holder, Ant_01_state);
			}
			else
			{
				transition_Ant_agent(current_xmachine_Ant_holder, Ant_01_state, Ant_04_state);
			}
		}

		current_xmachine_Ant = NULL;

		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish stayInNest\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_foodInformation)\n");
	rc = MB_SyncComplete(b_foodInformation);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_foodInformation)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'foodInformation' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foodInformation' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_pheromoneInformation)\n");
	rc = MB_SyncComplete(b_pheromoneInformation);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_pheromoneInformation)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'pheromoneInformation' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pheromoneInformation' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start walk\n");
	current_xmachine_Ant_holder = Ant_01_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		current_xmachine_Ant = current_xmachine_Ant_holder->agent;
		current_xmachine_Ant_next_state = Ant_02_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Ant = current_xmachine_Ant;

		if(FLAME_condition_Ant_walk_01_02(current_xmachine_Ant))
		{

		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = walk();

		
		    rc = MB_Iterator_Delete(&i_pheromoneInformation);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'pheromoneInformation' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'pheromoneInformation' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_foodInformation);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'foodInformation' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'foodInformation' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Ant_agent(current_xmachine_Ant_holder, Ant_01_state);
			}
			else
			{
				transition_Ant_agent(current_xmachine_Ant_holder, Ant_01_state, Ant_02_state);
			}
		}

		current_xmachine_Ant = NULL;

		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish walk\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_foodInformation)\n");
    rc = MB_SyncStart(b_foodInformation);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_foodInformation)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'foodInformation' board\n");
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_nestInformation)\n");
	rc = MB_SyncComplete(b_nestInformation);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_nestInformation)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'nestInformation' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'nestInformation' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start findNest\n");
	current_xmachine_Ant_holder = Ant_01_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		current_xmachine_Ant = current_xmachine_Ant_holder->agent;
		current_xmachine_Ant_next_state = Ant_02_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Ant = current_xmachine_Ant;

		if(FLAME_condition_Ant_findNest_01_02(current_xmachine_Ant))
		{

		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = findNest();

		
		    rc = MB_Iterator_Delete(&i_nestInformation);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'nestInformation' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'nestInformation' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		
		    rc = MB_Iterator_Delete(&i_pheromoneInformation);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'pheromoneInformation' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'pheromoneInformation' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Ant_agent(current_xmachine_Ant_holder, Ant_01_state);
			}
			else
			{
				transition_Ant_agent(current_xmachine_Ant_holder, Ant_01_state, Ant_02_state);
			}
		}

		current_xmachine_Ant = NULL;

		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish findNest\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_pheromoneInformation)\n");
    rc = MB_SyncStart(b_pheromoneInformation);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_pheromoneInformation)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'pheromoneInformation' board\n");
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	/* DEBUG: States with branching functions */
		current_xmachine_Ant_holder = Ant_02_state->agents;
		while(current_xmachine_Ant_holder)
		{
			FLAME_debug_count = 0;
			/* Function: depositIdle */
			if(FLAME_condition_Ant_depositIdle_02_04(current_xmachine_Ant_holder->agent))
			{ FLAME_debug_count++; }
			/* Function: deposit */
			if(FLAME_condition_Ant_deposit_02_03(current_xmachine_Ant_holder->agent))
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'Ant' leaving state '02'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start depositIdle\n");
	current_xmachine_Ant_holder = Ant_02_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		current_xmachine_Ant = current_xmachine_Ant_holder->agent;
		current_xmachine_Ant_next_state = Ant_04_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Ant = current_xmachine_Ant;

		if(FLAME_condition_Ant_depositIdle_02_04(current_xmachine_Ant))
		{

		

			i = depositIdle();

		

			if(i == 1)
			{
				free_Ant_agent(current_xmachine_Ant_holder, Ant_02_state);
			}
			else
			{
				transition_Ant_agent(current_xmachine_Ant_holder, Ant_02_state, Ant_04_state);
			}
		}

		current_xmachine_Ant = NULL;

		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish depositIdle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_pheromoneInformation)\n");
	rc = MB_SyncComplete(b_pheromoneInformation);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_pheromoneInformation)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'pheromoneInformation' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pheromoneInformation' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start deposit\n");
	current_xmachine_Ant_holder = Ant_02_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		current_xmachine_Ant = current_xmachine_Ant_holder->agent;
		current_xmachine_Ant_next_state = Ant_03_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Ant = current_xmachine_Ant;

		if(FLAME_condition_Ant_deposit_02_03(current_xmachine_Ant))
		{

		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = deposit();

		
		    rc = MB_Iterator_Delete(&i_pheromoneInformation);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'pheromoneInformation' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'pheromoneInformation' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Ant_agent(current_xmachine_Ant_holder, Ant_02_state);
			}
			else
			{
				transition_Ant_agent(current_xmachine_Ant_holder, Ant_02_state, Ant_03_state);
			}
		}

		current_xmachine_Ant = NULL;

		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish deposit\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_pheromoneIncreased)\n");
    rc = MB_SyncStart(b_pheromoneIncreased);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_pheromoneIncreased)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'pheromoneIncreased' board\n");
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_newPheromoneInput)\n");
    rc = MB_SyncStart(b_newPheromoneInput);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_newPheromoneInput)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'newPheromoneInput' board\n");
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	/* DEBUG: States with branching functions */
		current_xmachine_Ant_holder = Ant_03_state->agents;
		while(current_xmachine_Ant_holder)
		{
			FLAME_debug_count = 0;
			/* Function: forageIdle */
			if(FLAME_condition_Ant_forageIdle_03_04(current_xmachine_Ant_holder->agent))
			{ FLAME_debug_count++; }
			/* Function: forage */
			if(FLAME_condition_Ant_forage_03_04(current_xmachine_Ant_holder->agent))
			{ FLAME_debug_count++; }
			/*printf("FLAME_debug_count = %d\n", FLAME_debug_count);*/
			if(FLAME_debug_count != 1)
			{
				fprintf(stderr, "ERROR: A function condition test has failed for agent type 'Ant' leaving state '03'\n");
				if(FLAME_debug_count > 1)
					fprintf(stderr, "\t reason: there was more than one possible outgoing transition function\n");
				if(FLAME_debug_count == 0)
					fprintf(stderr, "\t reason: there was no possible outgoing transition function\n");
			}
			
			current_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		}
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start forageIdle\n");
	current_xmachine_Ant_holder = Ant_03_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		current_xmachine_Ant = current_xmachine_Ant_holder->agent;
		current_xmachine_Ant_next_state = Ant_04_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Ant = current_xmachine_Ant;

		if(FLAME_condition_Ant_forageIdle_03_04(current_xmachine_Ant))
		{

		

			i = forageIdle();

		

			if(i == 1)
			{
				free_Ant_agent(current_xmachine_Ant_holder, Ant_03_state);
			}
			else
			{
				transition_Ant_agent(current_xmachine_Ant_holder, Ant_03_state, Ant_04_state);
			}
		}

		current_xmachine_Ant = NULL;

		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish forageIdle\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_foodInformation)\n");
	rc = MB_SyncComplete(b_foodInformation);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_foodInformation)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'foodInformation' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foodInformation' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start forage\n");
	current_xmachine_Ant_holder = Ant_03_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		current_xmachine_Ant = current_xmachine_Ant_holder->agent;
		current_xmachine_Ant_next_state = Ant_04_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Ant = current_xmachine_Ant;

		if(FLAME_condition_Ant_forage_03_04(current_xmachine_Ant))
		{

		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = forage();

		
		    rc = MB_Iterator_Delete(&i_foodInformation);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'foodInformation' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'foodInformation' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Ant_agent(current_xmachine_Ant_holder, Ant_03_state);
			}
			else
			{
				transition_Ant_agent(current_xmachine_Ant_holder, Ant_03_state, Ant_04_state);
			}
		}

		current_xmachine_Ant = NULL;

		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish forage\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_foodEaten)\n");
    rc = MB_SyncStart(b_foodEaten);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_foodEaten)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'foodEaten' board\n");
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_pheromoneIncreased)\n");
	rc = MB_SyncComplete(b_pheromoneIncreased);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_pheromoneIncreased)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'pheromoneIncreased' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pheromoneIncreased' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start increasePheromoneLife\n");
	current_xmachine_Pheromone_holder = Pheromone_02_state->agents;
	while(current_xmachine_Pheromone_holder)
	{
		temp_xmachine_Pheromone_holder = current_xmachine_Pheromone_holder->next;
		current_xmachine_Pheromone = current_xmachine_Pheromone_holder->agent;
		current_xmachine_Pheromone_next_state = Pheromone_03_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Pheromone = current_xmachine_Pheromone;

		

		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = increasePheromoneLife();

		
		    rc = MB_Iterator_Delete(&i_pheromoneIncreased);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'pheromoneIncreased' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'pheromoneIncreased' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_02_state);
			}
			else
			{
				transition_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_02_state, Pheromone_03_state);
			}
		

		current_xmachine_Pheromone = NULL;

		current_xmachine_Pheromone_holder = temp_xmachine_Pheromone_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish increasePheromoneLife\n");


	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_newPheromoneInput)\n");
	rc = MB_SyncComplete(b_newPheromoneInput);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_newPheromoneInput)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'newPheromoneInput' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'newPheromoneInput' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start produce\n");
	current_xmachine_Generator_holder = Generator_00_state->agents;
	while(current_xmachine_Generator_holder)
	{
		temp_xmachine_Generator_holder = current_xmachine_Generator_holder->next;
		current_xmachine_Generator = current_xmachine_Generator_holder->agent;
		current_xmachine_Generator_next_state = Generator_01_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Generator = current_xmachine_Generator;

		

		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = produce();

		
		    rc = MB_Iterator_Delete(&i_newPheromoneInput);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'newPheromoneInput' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'newPheromoneInput' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Generator_agent(current_xmachine_Generator_holder, Generator_00_state);
			}
			else
			{
				transition_Generator_agent(current_xmachine_Generator_holder, Generator_00_state, Generator_01_state);
			}
		

		current_xmachine_Generator = NULL;

		current_xmachine_Generator_holder = temp_xmachine_Generator_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish produce\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_foodEaten)\n");
	rc = MB_SyncComplete(b_foodEaten);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_foodEaten)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'foodEaten' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foodEaten' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start updateFood\n");
	current_xmachine_Food_holder = Food_01_state->agents;
	while(current_xmachine_Food_holder)
	{
		temp_xmachine_Food_holder = current_xmachine_Food_holder->next;
		current_xmachine_Food = current_xmachine_Food_holder->agent;
		current_xmachine_Food_next_state = Food_02_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Food = current_xmachine_Food;

		

		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = updateFood();

		
		    rc = MB_Iterator_Delete(&i_foodEaten);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'foodEaten' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'foodEaten' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_Food_agent(current_xmachine_Food_holder, Food_01_state);
			}
			else
			{
				transition_Food_agent(current_xmachine_Food_holder, Food_01_state, Food_02_state);
			}
		

		current_xmachine_Food = NULL;

		current_xmachine_Food_holder = temp_xmachine_Food_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish updateFood\n");

// new

//new
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncStart(b_newFood)\n");
    rc = MB_SyncStart(b_newFood);
    if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finish MB_SyncStart(b_newFood)\n");
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not start sync of 'newFood' board\n");
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
           default:
               fprintf(stderr, "\t MB_SyncStart returned error code: %d (see libmboard docs for details)\n", rc);
               break;

       }

       
       exit(rc);
    }
    #endif


	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start decreaseFoodLevel\n");
	current_xmachine_Ant_holder = Ant_04_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		current_xmachine_Ant = current_xmachine_Ant_holder->agent;
		current_xmachine_Ant_next_state = Ant_05_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_Ant = current_xmachine_Ant;

		

		

			i = decreaseFoodLevel();

		

			if(i == 1)
			{
				free_Ant_agent(current_xmachine_Ant_holder, Ant_04_state);
			}
			else
			{
				transition_Ant_agent(current_xmachine_Ant_holder, Ant_04_state, Ant_05_state);
			}
		

		current_xmachine_Ant = NULL;

		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish decreaseFoodLevel\n");



	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("start MB_SyncComplete(b_newFood)\n");
	rc = MB_SyncComplete(b_newFood);
	if(FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS) printf("finsh MB_SyncComplete(b_newFood)\n");
	#ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not complete sync of 'newFood' board\n");
       switch(rc) {
            case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'newFood' board is invalid\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
           default:
               fprintf(stderr, "\t MB_SyncComplete returned error code: %d (see libmboard docs for details)\n", rc);
               break;
       }

       
       exit(rc);
    }
    #endif
    
	
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("start produceFood\n");
	current_xmachine_FoodGenerator_holder = FoodGenerator_00_state->agents;
	while(current_xmachine_FoodGenerator_holder)
	{
		temp_xmachine_FoodGenerator_holder = current_xmachine_FoodGenerator_holder->next;
		current_xmachine_FoodGenerator = current_xmachine_FoodGenerator_holder->agent;
		current_xmachine_FoodGenerator_next_state = FoodGenerator_01_state;
		/* For backwards compatibility set current_xmachine */
		current_xmachine->xmachine_Ant = NULL;
		current_xmachine->xmachine_Pheromone = NULL;
		current_xmachine->xmachine_Generator = NULL;
		current_xmachine->xmachine_FoodGenerator = NULL;
		current_xmachine->xmachine_Nest = NULL;
		current_xmachine->xmachine_Food = NULL;
		current_xmachine->xmachine_FoodGenerator = current_xmachine_FoodGenerator;

		

		
		
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
	           default:
	           
               
                   fprintf(stderr, "\t MB_Iterator_Create returned error code: %d (see libmboard docs for details)\n", rc);
               
                   break;
		   }

		   
           exit(rc);
		}
		#endif
		
		

			i = produceFood();

		
		    rc = MB_Iterator_Delete(&i_newFood);
		    #ifdef ERRCHECK
		    if (rc != MB_SUCCESS)
		    {
		       fprintf(stderr, "ERROR: Could not delete 'newFood' iterator\n");
		       switch(rc) {
		           case MB_ERR_INVALID:
		               fprintf(stderr, "\t reason: 'newFood' iterator is invalid\n");
		               break;
		           case MB_ERR_INTERNAL:
		               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
		               break;
		           default:
                       fprintf(stderr, "\t MB_Iterator_Delete returned error code: %d (see libmboard docs for details)\n", rc);
                       break;
		       }

		       
               exit(rc);
		    }
		    #endif
		

			if(i == 1)
			{
				free_FoodGenerator_agent(current_xmachine_FoodGenerator_holder, FoodGenerator_00_state);
			}
			else
			{
				transition_FoodGenerator_agent(current_xmachine_FoodGenerator_holder, FoodGenerator_00_state, FoodGenerator_01_state);
			}
		

		current_xmachine_FoodGenerator = NULL;

		current_xmachine_FoodGenerator_holder = temp_xmachine_FoodGenerator_holder;
	}
	if(FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS) printf("finish produceFood\n");




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

	if(iteration_loop%output_frequency == output_offset)
	{
		saveiterationdata(iteration_loop);
	}

	/*printf("Ant_05_state->count = %d\n", Ant_05_state->count);*/
	Ant_05_state->count = 0;

	/*printf("Ant_03_state->count = %d\n", Ant_03_state->count);*/
	Ant_03_state->count = 0;

	/*printf("Ant_02_state->count = %d\n", Ant_02_state->count);*/
	Ant_02_state->count = 0;

	/*printf("Ant_04_state->count = %d\n", Ant_04_state->count);*/
	Ant_04_state->count = 0;

	/*printf("Ant_01_state->count = %d\n", Ant_01_state->count);*/
	Ant_01_state->count = 0;

	/*printf("Ant_00_state->count = %d\n", Ant_00_state->count);*/
	Ant_00_state->count = 0;

	/*printf("Pheromone_03_state->count = %d\n", Pheromone_03_state->count);*/
	Pheromone_03_state->count = 0;

	/*printf("Pheromone_02_state->count = %d\n", Pheromone_02_state->count);*/
	Pheromone_02_state->count = 0;

	/*printf("Pheromone_01_state->count = %d\n", Pheromone_01_state->count);*/
	Pheromone_01_state->count = 0;

	/*printf("Pheromone_00_state->count = %d\n", Pheromone_00_state->count);*/
	Pheromone_00_state->count = 0;

	/*printf("Generator_01_state->count = %d\n", Generator_01_state->count);*/
	Generator_01_state->count = 0;

	/*printf("Generator_00_state->count = %d\n", Generator_00_state->count);*/
	Generator_00_state->count = 0;

	/*printf("FoodGenerator_01_state->count = %d\n", FoodGenerator_01_state->count);*/
	FoodGenerator_01_state->count = 0;

	/*printf("FoodGenerator_00_state->count = %d\n", FoodGenerator_00_state->count);*/
	FoodGenerator_00_state->count = 0;

	/*printf("Nest_01_state->count = %d\n", Nest_01_state->count);*/
	Nest_01_state->count = 0;

	/*printf("Nest_00_state->count = %d\n", Nest_00_state->count);*/
	Nest_00_state->count = 0;

	/*printf("Food_02_state->count = %d\n", Food_02_state->count);*/
	Food_02_state->count = 0;

	/*printf("Food_01_state->count = %d\n", Food_01_state->count);*/
	Food_01_state->count = 0;

	/*printf("Food_00_state->count = %d\n", Food_00_state->count);*/
	Food_00_state->count = 0;

	/* Move agents to their start states */

	current_xmachine_Ant_holder = Ant_05_state->agents;
	while(current_xmachine_Ant_holder)
	{
		temp_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
		transition_Ant_agent(current_xmachine_Ant_holder, Ant_05_state, Ant_00_state);

		current_xmachine_Ant_holder = temp_xmachine_Ant_holder;
	}

	current_xmachine_Pheromone_holder = Pheromone_03_state->agents;
	while(current_xmachine_Pheromone_holder)
	{
		temp_xmachine_Pheromone_holder = current_xmachine_Pheromone_holder->next;
		transition_Pheromone_agent(current_xmachine_Pheromone_holder, Pheromone_03_state, Pheromone_00_state);

		current_xmachine_Pheromone_holder = temp_xmachine_Pheromone_holder;
	}

	current_xmachine_Generator_holder = Generator_01_state->agents;
	while(current_xmachine_Generator_holder)
	{
		temp_xmachine_Generator_holder = current_xmachine_Generator_holder->next;
		transition_Generator_agent(current_xmachine_Generator_holder, Generator_01_state, Generator_00_state);

		current_xmachine_Generator_holder = temp_xmachine_Generator_holder;
	}

	current_xmachine_FoodGenerator_holder = FoodGenerator_01_state->agents;
	while(current_xmachine_FoodGenerator_holder)
	{
		temp_xmachine_FoodGenerator_holder = current_xmachine_FoodGenerator_holder->next;
		transition_FoodGenerator_agent(current_xmachine_FoodGenerator_holder, FoodGenerator_01_state, FoodGenerator_00_state);

		current_xmachine_FoodGenerator_holder = temp_xmachine_FoodGenerator_holder;
	}

	current_xmachine_Nest_holder = Nest_01_state->agents;
	while(current_xmachine_Nest_holder)
	{
		temp_xmachine_Nest_holder = current_xmachine_Nest_holder->next;
		transition_Nest_agent(current_xmachine_Nest_holder, Nest_01_state, Nest_00_state);

		current_xmachine_Nest_holder = temp_xmachine_Nest_holder;
	}

	current_xmachine_Food_holder = Food_02_state->agents;
	while(current_xmachine_Food_holder)
	{
		temp_xmachine_Food_holder = current_xmachine_Food_holder->next;
		transition_Food_agent(current_xmachine_Food_holder, Food_02_state, Food_00_state);

		current_xmachine_Food_holder = temp_xmachine_Food_holder;
	}


		/* Calculate if any agents need to jump S.P. */
		/* propagate_agents(); */
	/* Save iteration time to log file */

		file = fopen(logfilepath, "a");
		fputs("<iteration><no>", file);
		sprintf(data, "%i", iteration_loop);
		fputs(data, file);
		fputs("</no><time>", file);
		sprintf(data, "%d", (int)((get_time() - interval) * 1000) );
		fputs(data, file);
		fputs("</time></iteration>\n", file);
		fclose(file);

	}

	/* Stop timing and print total time */
	stop = get_time();
	total_time = stop - start;
	printf("Execution time - %d:%02d:%03d [mins:secs:msecs]\n",
       (int)(total_time/60), ((int)total_time)%60, (((int)(total_time * 1000.0)) % 1000));

	clean_up(0);

	/* Exit successfully by returning zero to Operating System */
	return 0;
}
