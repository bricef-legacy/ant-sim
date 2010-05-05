/**
 * \file  xml.c
 * \brief Holds xml reading and writing functions.
 */

#include "header.h"

/** \fn void read_int_static_array(char * buffer, int * j, int ** int_static_array)
 * \brief Reads integer static array.
 */
int read_int_static_array(char * buffer, int buffer_size, int * j, int * int_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];
	
	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		int_static_array[arraycount] = atoi(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_float_static_array(char * buffer, int * (*j), int ** float_static_array)
 * \brief Reads float static array.
 */
int read_float_static_array(char * buffer, int buffer_size, int * j, float * float_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		float_static_array[arraycount] = atof(arraydata);
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_double_static_array(char * buffer, int * (*j), int ** double_static_array)
 * \brief Reads double static array.
 */
int read_double_static_array(char * buffer, int buffer_size, int * j, double * double_static_array, int size)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		double_static_array[arraycount] = atof(arraydata);		
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_char_static_array(char * buffer, int * (*j), int ** char_static_array)
 * \brief Reads char static array.
 */
int read_char_static_array(char * buffer, int buffer_size, int * j, char * char_static_array, int size)
{
	int arraycount;
	
	while(buffer[(*j)] == ' ')
	{
		(*j)++;
	}
	
	for(arraycount = 0; arraycount < size; arraycount++)
	{
		char_static_array[arraycount] = buffer[(*j)];
		(*j)++;
	}

	//(*j)++;
	return 0;
}

/** \fn void read_int_dynamic_array(char * buffer, int * (*j), int ** int_dynamic_array)
 * \brief Reads integer dynamic array.
 */
int read_int_dynamic_array(char * buffer, int buffer_size, int * j, int_array * int_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		add_int(int_dynamic_array, atoi(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_float_dynamic_array(char * buffer, int * (*j), int ** float_dynamic_array)
 * \brief Reads float dynamic array.
 */
int read_float_dynamic_array(char * buffer, int buffer_size, int * j, float_array * float_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		add_float(float_dynamic_array, atof(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_double_dynamic_array(char * buffer, int * (*j), int ** double_dynamic_array)
 * \brief Reads double dynamic array.
 */
int read_double_dynamic_array(char * buffer, int buffer_size, int * j, double_array * double_dynamic_array)
{
	int arraycount = 0;
	int array_k;
	char arraydata[10000];

	while(buffer[(*j)] != '{')
	{
		if(buffer[(*j)] != ' ') return -1;
		else if(buffer[(*j)] == '\0') return -1;
		else (*j)++;
	}
	(*j)++;

	while(buffer[(*j)] != '}')
	{
		array_k = 0;
		while(buffer[(*j)] != ',' && buffer[(*j)] != '}')
		{
			if(buffer[(*j)] == '\0') return -1;
			arraydata[array_k] = buffer[(*j)];
			array_k++;
			(*j)++;
		}
		arraydata[array_k] = 0;
		add_double(double_dynamic_array, atof(arraydata));
		arraycount++;
		if(buffer[(*j)] != '}') (*j)++;
	}

	(*j)++;
	return 0;
}

/** \fn void read_char_dynamic_array(char * buffer, int * (*j), int ** char_dynamic_array)
 * \brief Reads char dynamic array.
 */
int read_char_dynamic_array(char * buffer, int buffer_size, int * j, char_array * char_dynamic_array)
{
	if(*j > buffer_size) return -1;
	
	while(buffer[(*j)] == ' ')
	{
		(*j)++;
	}
	
	while(buffer[(*j)] != '\0' && buffer[(*j)] != ',' && buffer[(*j)] != '}')
	{
		add_char(char_dynamic_array, buffer[(*j)]);
		(*j)++;
	}
	
	return 0;
}




int readEnvironmentXML(char * location)
{
	FILE * file;
	char c = '\0';
	char buffer[10000];
	int index = 0;
	int in_environment = 0;
	

	buffer[0] = '\0';

	/* Open file */
	if((file = fopen(location, "r"))==NULL)
	{
		printf("Error: cannot open import xml file '%s'\n", location);
		exit(0);
	}
	printf("Reading environment data from: %s\n", location);
	/* Keep reading file until EOF */
	while(c != (char)EOF)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);
		if(c == '>')
		{
			buffer[index] = '\0';
			if(strcmp(buffer, "environment") == 0) in_environment = 1;
			if(strcmp(buffer, "/environment") == 0) in_environment = 0;
			
			index = 0;
			buffer[index] = '\0';
		}
		else if(c == '<')
		{
			buffer[index] = '\0';
			if(in_environment)
			{
				
			}
			index = 0;
			buffer[index] = '\0';
		}
		else
		{
			buffer[index] = c;
			if(index < 999) index++;
		}
	}
	/* Close file */
	fclose(file);

	return 0;
}

int readAgentXML(char * location,
				double cloud_data[6],
				int partition_method,
				int flag,
				int number_partitions,
				int agent_count)
{
	FILE * file;
	char c = '\0';
	char buffer[100000];
	char agentname[10000];
	int index = 0;
	int j = 0; /* Index for reading arrays */
	int rc;
	int FLAME_in_xagent = 0;
	int FLAME_in_name = 0;
	int in_Ant_agent = 0;
	int in_Pheromone_agent = 0;
	int in_Generator_agent = 0;
	int in_FoodGenerator_agent = 0;
	int in_Nest_agent = 0;
	int in_Food_agent = 0;
	
	int in_antID = 0;
	int in_antX = 0;
	int in_antY = 0;
	int in_foodLevel = 0;
	int in_isFed = 0;
	int in_isInNest = 0;
	int in_antDirection = 0;
	int in_state = 0;
	int in_pheromoneID = 0;
	int in_life = 0;
	int in_pheromoneX = 0;
	int in_pheromoneY = 0;
	int in_memoryID = 0;
	int in_memoryFoodID = 0;
	int in_nestX = 0;
	int in_nestY = 0;
	int in_nestRadius = 0;
	int in_foodID = 0;
	int in_size = 0;
	int in_foodX = 0;
	int in_foodY = 0;
	int in_radius = 0;
	
	xmachine_memory_Ant * current_Ant_agent = NULL;
	xmachine_memory_Pheromone * current_Pheromone_agent = NULL;
	xmachine_memory_Generator * current_Generator_agent = NULL;
	xmachine_memory_FoodGenerator * current_FoodGenerator_agent = NULL;
	xmachine_memory_Nest * current_Nest_agent = NULL;
	xmachine_memory_Food * current_Food_agent = NULL;
	
	/* Things for round-robin partitioning */
	int geometric = 1;
	int other = 2;
	double 	xmax=0, xmin=0, ymax=0, ymin=0;
	double xcentre=0, ycentre=0, rrange=1.5;
	double posx=0.0, posy=0.0, posz=0.0;

	agentname[0] = '\0';
	buffer[0] = '\0';

	/* Open file */
	if((file = fopen(location, "r"))==NULL)
	{
		printf("Error: cannot open import xml file '%s'\n", location);
		exit(1);
	}
	printf("Reading agent data from: %s\n", location);
	/* Keep reading file until EOF */
	while(c != (char)EOF)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);
		if(c == '>')
		{
			buffer[index] = '\0';
			if(strcmp(buffer, "xagent") == 0)
			{
				FLAME_in_xagent = 1;
				agentname[0] = '\0';
			}
			if(strcmp(buffer, "/xagent") == 0)
			{
				if(strcmp(agentname, "Ant") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;

					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_Ant_agent_internal(current_Ant_agent, Ant_00_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_Ant_agent_internal(current_Ant_agent, Ant_00_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								add_Ant_agent_internal(current_Ant_agent, Ant_00_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "Pheromone") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;

					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_Pheromone_agent_internal(current_Pheromone_agent, Pheromone_00_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_Pheromone_agent_internal(current_Pheromone_agent, Pheromone_00_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								add_Pheromone_agent_internal(current_Pheromone_agent, Pheromone_00_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "Generator") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;

					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_Generator_agent_internal(current_Generator_agent, Generator_00_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_Generator_agent_internal(current_Generator_agent, Generator_00_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								add_Generator_agent_internal(current_Generator_agent, Generator_00_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "FoodGenerator") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;

					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_FoodGenerator_agent_internal(current_FoodGenerator_agent, FoodGenerator_00_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_FoodGenerator_agent_internal(current_FoodGenerator_agent, FoodGenerator_00_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								add_FoodGenerator_agent_internal(current_FoodGenerator_agent, FoodGenerator_00_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "Nest") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;

					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_Nest_agent_internal(current_Nest_agent, Nest_00_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_Nest_agent_internal(current_Nest_agent, Nest_00_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								add_Nest_agent_internal(current_Nest_agent, Nest_00_state);
							}
							++agent_count;
						}
					}
				}
				else if(strcmp(agentname, "Food") == 0)
				{
					posx = 0.0;
					posy = 0.0;
					posz = 0.0;

					
					/* If flag is zero just read the data. We'll partition later.
					 * If flag is not zero we aleady have partition data so can read and distribute to the current node.*/
					if( flag == 0 )
					{
						/* Next line should be commented out? */
						add_Food_agent_internal(current_Food_agent, Food_00_state);

						/* Update the cloud data */
						if ( posx < cloud_data[0] ) cloud_data[0] = posx;
						if ( posx > cloud_data[1] ) cloud_data[1] = posx;
						if ( posy < cloud_data[2] ) cloud_data[2] = posy;
						if ( posy > cloud_data[3] ) cloud_data[3] = posy;
						if ( posz < cloud_data[2] ) cloud_data[4] = posz;
						if ( posz > cloud_data[3] ) cloud_data[5] = posz;
					}
					else
					{
						if(partition_method == geometric)
						{
							if (
								((current_node->partition_data[0] == SPINF) || (current_node->partition_data[0] != SPINF && posx >= current_node->partition_data[0])) &&
								((current_node->partition_data[1] == SPINF) || (current_node->partition_data[1] != SPINF && posx < current_node->partition_data[1])) &&
								((current_node->partition_data[2] == SPINF) || (current_node->partition_data[2] != SPINF && posy >= current_node->partition_data[2])) &&
								((current_node->partition_data[3] == SPINF) || (current_node->partition_data[3] != SPINF && posy < current_node->partition_data[3])) &&
								((current_node->partition_data[4] == SPINF) || (current_node->partition_data[4] != SPINF && posz >= current_node->partition_data[4])) &&
								((current_node->partition_data[5] == SPINF) || (current_node->partition_data[5] != SPINF && posz < current_node->partition_data[5]))
							)
							{
								add_Food_agent_internal(current_Food_agent, Food_00_state);
							}
						}
						else if (partition_method == other)
						{
							if (agent_count % number_partitions == 0)
							{
								/* Compute centre of partition */
								xmin=current_node->partition_data[0];
								xmax=current_node->partition_data[1];
								ymin=current_node->partition_data[2];
								ymax=current_node->partition_data[3];

								xcentre=xmin+(xmax-xmin)/2.0;
								ycentre=ymin+(ymax-ymin)/2.0;
								rrange=1.5;

								add_Food_agent_internal(current_Food_agent, Food_00_state);
							}
							++agent_count;
						}
					}
				}
				else
				{
					printf("Warning: agent name undefined - '%s'\n", agentname);
					exit(0);
				}
				agentname[0] = '\0';
				FLAME_in_xagent = 0;
				in_Ant_agent = 0;
				in_Pheromone_agent = 0;
				in_Generator_agent = 0;
				in_FoodGenerator_agent = 0;
				in_Nest_agent = 0;
				in_Food_agent = 0;
				
			}
			if(strcmp(buffer, "name") == 0) FLAME_in_name = 1;
			if(strcmp(buffer, "/name") == 0) FLAME_in_name = 0;
			if(strcmp(buffer, "antID") == 0) { in_antID = 1; }
			if(strcmp(buffer, "/antID") == 0) { in_antID = 0; }
			if(strcmp(buffer, "antX") == 0) { in_antX = 1; }
			if(strcmp(buffer, "/antX") == 0) { in_antX = 0; }
			if(strcmp(buffer, "antY") == 0) { in_antY = 1; }
			if(strcmp(buffer, "/antY") == 0) { in_antY = 0; }
			if(strcmp(buffer, "foodLevel") == 0) { in_foodLevel = 1; }
			if(strcmp(buffer, "/foodLevel") == 0) { in_foodLevel = 0; }
			if(strcmp(buffer, "isFed") == 0) { in_isFed = 1; }
			if(strcmp(buffer, "/isFed") == 0) { in_isFed = 0; }
			if(strcmp(buffer, "isInNest") == 0) { in_isInNest = 1; }
			if(strcmp(buffer, "/isInNest") == 0) { in_isInNest = 0; }
			if(strcmp(buffer, "antDirection") == 0) { in_antDirection = 1; }
			if(strcmp(buffer, "/antDirection") == 0) { in_antDirection = 0; }
			if(strcmp(buffer, "state") == 0) { in_state = 1; }
			if(strcmp(buffer, "/state") == 0) { in_state = 0; }
			if(strcmp(buffer, "pheromoneID") == 0) { in_pheromoneID = 1; }
			if(strcmp(buffer, "/pheromoneID") == 0) { in_pheromoneID = 0; }
			if(strcmp(buffer, "life") == 0) { in_life = 1; }
			if(strcmp(buffer, "/life") == 0) { in_life = 0; }
			if(strcmp(buffer, "pheromoneX") == 0) { in_pheromoneX = 1; }
			if(strcmp(buffer, "/pheromoneX") == 0) { in_pheromoneX = 0; }
			if(strcmp(buffer, "pheromoneY") == 0) { in_pheromoneY = 1; }
			if(strcmp(buffer, "/pheromoneY") == 0) { in_pheromoneY = 0; }
			if(strcmp(buffer, "memoryID") == 0) { in_memoryID = 1; }
			if(strcmp(buffer, "/memoryID") == 0) { in_memoryID = 0; }
			if(strcmp(buffer, "memoryFoodID") == 0) { in_memoryFoodID = 1; }
			if(strcmp(buffer, "/memoryFoodID") == 0) { in_memoryFoodID = 0; }
			if(strcmp(buffer, "nestX") == 0) { in_nestX = 1; }
			if(strcmp(buffer, "/nestX") == 0) { in_nestX = 0; }
			if(strcmp(buffer, "nestY") == 0) { in_nestY = 1; }
			if(strcmp(buffer, "/nestY") == 0) { in_nestY = 0; }
			if(strcmp(buffer, "nestRadius") == 0) { in_nestRadius = 1; }
			if(strcmp(buffer, "/nestRadius") == 0) { in_nestRadius = 0; }
			if(strcmp(buffer, "foodID") == 0) { in_foodID = 1; }
			if(strcmp(buffer, "/foodID") == 0) { in_foodID = 0; }
			if(strcmp(buffer, "size") == 0) { in_size = 1; }
			if(strcmp(buffer, "/size") == 0) { in_size = 0; }
			if(strcmp(buffer, "foodX") == 0) { in_foodX = 1; }
			if(strcmp(buffer, "/foodX") == 0) { in_foodX = 0; }
			if(strcmp(buffer, "foodY") == 0) { in_foodY = 1; }
			if(strcmp(buffer, "/foodY") == 0) { in_foodY = 0; }
			if(strcmp(buffer, "radius") == 0) { in_radius = 1; }
			if(strcmp(buffer, "/radius") == 0) { in_radius = 0; }
			
			index = 0;
			buffer[index] = '\0';
		}
		else if(c == '<')
		{
			buffer[index] = '\0';
			if(FLAME_in_xagent)
			{
				if(FLAME_in_name)
				{
					strcpy(agentname, buffer);

					if(strcmp(agentname, "Ant") == 0)
					{
						current_Ant_agent = init_Ant_agent();
						in_Ant_agent = 1;
					}
					else if(strcmp(agentname, "Pheromone") == 0)
					{
						current_Pheromone_agent = init_Pheromone_agent();
						in_Pheromone_agent = 1;
					}
					else if(strcmp(agentname, "Generator") == 0)
					{
						current_Generator_agent = init_Generator_agent();
						in_Generator_agent = 1;
					}
					else if(strcmp(agentname, "FoodGenerator") == 0)
					{
						current_FoodGenerator_agent = init_FoodGenerator_agent();
						in_FoodGenerator_agent = 1;
					}
					else if(strcmp(agentname, "Nest") == 0)
					{
						current_Nest_agent = init_Nest_agent();
						in_Nest_agent = 1;
					}
					else if(strcmp(agentname, "Food") == 0)
					{
						current_Food_agent = init_Food_agent();
						in_Food_agent = 1;
					}
					else
					{
						printf("Warning: agent name undefined - '%s'\n", agentname);
						exit(0);
					}
				}
				else if(in_Ant_agent == 1)
				{
					if(in_antID) { current_Ant_agent->antID = atoi(buffer); }
					if(in_antX) { current_Ant_agent->antX = atof(buffer); }
					if(in_antY) { current_Ant_agent->antY = atof(buffer); }
					if(in_foodLevel) { current_Ant_agent->foodLevel = atof(buffer); }
					if(in_isFed) { current_Ant_agent->isFed = atoi(buffer); }
					if(in_isInNest) { current_Ant_agent->isInNest = atoi(buffer); }
					if(in_antDirection) { current_Ant_agent->antDirection = atoi(buffer); }
					if(in_state) { current_Ant_agent->state = atoi(buffer); }
				 }else if(in_Pheromone_agent == 1)
				{
					if(in_pheromoneID) { current_Pheromone_agent->pheromoneID = atoi(buffer); }
					if(in_life) { current_Pheromone_agent->life = atof(buffer); }
					if(in_pheromoneX) { current_Pheromone_agent->pheromoneX = atof(buffer); }
					if(in_pheromoneY) { current_Pheromone_agent->pheromoneY = atof(buffer); }
				 }else if(in_Generator_agent == 1)
				{
					if(in_memoryID) { current_Generator_agent->memoryID = atoi(buffer); }
				 }else if(in_FoodGenerator_agent == 1)
				{
					if(in_memoryFoodID) { current_FoodGenerator_agent->memoryFoodID = atoi(buffer); }
				 }else if(in_Nest_agent == 1)
				{
					if(in_nestX) { current_Nest_agent->nestX = atof(buffer); }
					if(in_nestY) { current_Nest_agent->nestY = atof(buffer); }
					if(in_nestRadius) { current_Nest_agent->nestRadius = atof(buffer); }
				 }else if(in_Food_agent == 1)
				{
					if(in_foodID) { current_Food_agent->foodID = atoi(buffer); }
					if(in_size) { current_Food_agent->size = atof(buffer); }
					if(in_foodX) { current_Food_agent->foodX = atof(buffer); }
					if(in_foodY) { current_Food_agent->foodY = atof(buffer); }
					if(in_radius) { current_Food_agent->radius = atof(buffer); }
				 }
			}
			index = 0;
			buffer[index] = '\0';
		}
		else
		{
			buffer[index] = c;
			if(index < 99999) index++;
			else
			{
				printf("Error: agent reading buffer too small\n");
				printf("%s\n", buffer);
				exit(0);
			}
		}
	}
	/* Close file */
	fclose(file);

	return 0;
}

/** \fn void check_location_exists(char * location)
 * \brief Check that a directory exists.
 * \param location The directory location to check.
 */
int check_location_exists(char * location)
{
	/* Save a dummy file to directory and remove.
	 * This checks directory exists and is writable */
	FILE * file;
	char * buffer;

	buffer = (char *)malloc( (strlen(location) + strlen("dummy.temp") + 1) * sizeof(char));
	strcpy(buffer, location);
	strcat(buffer, "dummy.temp");

	if((file = fopen(buffer, "w")) == NULL) return 0;

	fclose(file);
	/* Remove dummy file */
	remove(buffer);

	return 1;
}


/** \fn void readinitialstates(char * filename, int * itno, xmachine ** agent_list, double cloud_data[6], int flag)
 * \brief Read initial X-machine memory starting values from a file.
 * \param filename The path to the file.
 * \param filelocation The directory of the location
 * \param itno Pointer to the iteration number.
 * \param agent_list List of agents in the model to be constructed by this function.
 * \param cloud_data Max and min x,y,z coordinates of agents.
 * \param partition_method Identifies partitioning method: 1 = geometric, 2 = round-robin
 * \param flag Flag for whether to check space partitions.
 */
void readinitialstates(char * filename, char * filelocation, int * itno, double cloud_data[6],
					   int partition_method, int flag)
{
	/* Pointer to file */
	FILE *file;
	/* Char and char buffer for reading file to */
	char c = '\0';
	char buffer[100000];
	char FLAME_location[1000];
	char FLAME_format[1000];
	char FLAME_type[1000];
	FLAME_output * current_FLAME_output = NULL;

	/* Things for round-robin partitioning */
	int agent_count = 0;
	int number_partitions = 0;
	int geometric=1;
	int other=2;
	

	/* Cloud data array initialisation */
	cloud_data[0] = SPINF; cloud_data[1] = -SPINF;
	cloud_data[2] = SPINF; cloud_data[3] = -SPINF;
	cloud_data[4] = SPINF; cloud_data[5] = -SPINF;

	/* Temporary node and head of associated agent list to allow adding agents */
	node_information temp_node;

	/* Pointer to x-memory for initial state data */
	/*xmachine * current_xmachine;*/
	/* Variables for checking tags */
	int reading = 1;
	int i = 0;
	int rc;
	int in_tag = 0;
	int in_itno = 0;
	int FLAME_in_imports = 0;
	int FLAME_in_import = 0;
	int FLAME_in_outputs = 0;
	int FLAME_in_output = 0;
	int FLAME_in_location = 0;
	int FLAME_in_format = 0;
	int FLAME_in_type = 0;
	int FLAME_in_time = 0;
	int FLAME_in_period = 0;
	int FLAME_in_phase = 0;
	int FLAME_in_name = 0;

	/* Initialise environment vars */
	

	/* Open config file to read-only */
	if((file = fopen(filename, "r"))==NULL)
	{
		printf("Error: opening initial states '%s'\n", filename);
		exit(0);
	}
	
	/* Initialise variables */
    *itno = 0;





	if(partition_method==geometric) printf("xml: Geometric partitioning\n");
	else if(partition_method==other) printf("xml: Round-robin partitioning\n");
	else printf("xml: Error - invalid partitioning method\n");


	/* Set p_xmachine to the agent list passed in then new agents are added to this list
	 * Will be set to agent list for specific node is space partitions are already known (flag=1)
	 */
	/* If we're reading without knowing partitions already then use the dummy current node (it's not in the list of nodes)*/
	if (flag == 0) current_node = &temp_node;

	printf("Reading initial data file: %s\n", filename);
	/* Read file until end of xml */
	while(reading==1)
	{
		/* Get the next char from the file */
		c = (char)fgetc(file);

		/* If the end of a tag */
		if(c == '>')
		{
			/* Place 0 at end of buffer to make chars a string */
			buffer[i] = 0;

			if(strcmp(buffer, "states") == 0) reading = 1;
			if(strcmp(buffer, "/states") == 0) reading = 0;
			if(strcmp(buffer, "itno") == 0) in_itno = 1;
			if(strcmp(buffer, "/itno") == 0) in_itno = 0;
			if(strcmp(buffer, "imports") == 0) FLAME_in_imports = 1;
			if(strcmp(buffer, "/imports") == 0) FLAME_in_imports = 0;
			if(strcmp(buffer, "import") == 0)
			{
				/*FLAME_location[0] = '\0';*/
				strcpy(FLAME_location, filelocation);
				FLAME_format[0] = '\0';
				FLAME_type[0] = '\0';

				FLAME_in_import = 1;
			}
			if(strcmp(buffer, "/import") == 0)
			{
				if(strcmp("agent", FLAME_type) == 0 || strcmp("environment", FLAME_type) == 0)
				{
					if(strcmp("xml", FLAME_format) == 0)
					{
						if(strcmp("agent", FLAME_type) == 0) readAgentXML(FLAME_location, cloud_data, partition_method, flag, number_partitions, agent_count);
						if(strcmp("environment", FLAME_type) == 0) readEnvironmentXML(FLAME_location);
					}
					else
					{
						printf("Error: import format '%s' is unsupported\n", FLAME_format);
						exit(0);
					}
				}
				else
				{
					printf("Error: import type '%s' is not agent or environment\n", FLAME_type);
					exit(0);
				}

				FLAME_in_import = 0;
			}
			if(strcmp(buffer, "location") == 0) FLAME_in_location = 1;
			if(strcmp(buffer, "/location") == 0) FLAME_in_location = 0;
			if(strcmp(buffer, "format") == 0) FLAME_in_format = 1;
			if(strcmp(buffer, "/format") == 0) FLAME_in_format = 0;
			if(strcmp(buffer, "type") == 0) FLAME_in_type = 1;
			if(strcmp(buffer, "/type") == 0) FLAME_in_type = 0;
			if(strcmp(buffer, "outputs") == 0) FLAME_in_outputs = 1;
			if(strcmp(buffer, "/outputs") == 0) FLAME_in_outputs = 0;
			if(strcmp(buffer, "output") == 0)
			{
				if(FLAME_in_outputs)
				{
					current_FLAME_output = add_FLAME_output(&FLAME_outputs);
	
					FLAME_in_output = 1;
				}
			}
			if(strcmp(buffer, "/output") == 0)
			{
				if(FLAME_in_outputs)
				{
					if(current_FLAME_output->type == -1)
					{
						printf("Error: an output type has not been set\n");
						exit(0);
					}
					if(current_FLAME_output->format == -1)
					{
						printf("Error: an output format has not been set\n");
						exit(0);
					}
					if(current_FLAME_output->location == NULL)
					{
						printf("Error: an output location has not been set\n");
						exit(0);
					}
					/* If type is xml check if location exists */
					if(current_FLAME_output->type == 0)
					{
						rc = check_location_exists(current_FLAME_output->location);
						if(rc == 0)
						{
							printf("Error: location directory '%s' does not exist\n", current_FLAME_output->location);
							exit(0);
						}
					}
					/* Period has to be larger than 0 */
					if(current_FLAME_output->period < 1)
					{
						printf("Error: output period is less than 1: '%d'\n", current_FLAME_output->period);
						exit(0);
					}
					/* Phase cannot be equal or larger than period */
					if(current_FLAME_output->phase >= current_FLAME_output->period)
					{
						printf("Error: output phase is more or equal to period: '%d'\n", current_FLAME_output->phase);
						exit(0);
					}
	
					FLAME_in_output = 0;
				}
			}
			if(strcmp(buffer, "time") == 0) FLAME_in_time = 1;
			if(strcmp(buffer, "/time") == 0) FLAME_in_time = 0;
			if(strcmp(buffer, "period") == 0) FLAME_in_period = 1;
			if(strcmp(buffer, "/period") == 0) FLAME_in_period = 0;
			if(strcmp(buffer, "phase") == 0) FLAME_in_phase = 1;
			if(strcmp(buffer, "/phase") == 0) FLAME_in_phase = 0;
			if(strcmp(buffer, "name") == 0) FLAME_in_name = 1;
			if(strcmp(buffer, "/name") == 0) FLAME_in_name = 0;

			/* End of tag and reset buffer */
			in_tag = 0;
			i = 0;
		}
		/* If start of tag */
		else if(c == '<')
		{
			/* Place /0 at end of buffer to end numbers */
			buffer[i] = 0;
			/* Flag in tag */
			in_tag = 1;

			if(in_itno) *itno = atoi(buffer);
			if(FLAME_in_imports)
			{
				if(FLAME_in_import)
				{
					if(FLAME_in_location) strcat(FLAME_location, buffer);
					if(FLAME_in_format) strcpy(FLAME_format, buffer);
					if(FLAME_in_type) strcpy(FLAME_type, buffer);
				}
			}
			if(FLAME_in_outputs)
			{
				if(FLAME_in_output)
				{
					if(FLAME_in_type)
					{
						if(strcmp("snapshot", buffer) == 0) current_FLAME_output->type = 0;
						else if(strcmp("agent", buffer) != 0)
						{
							printf("Error: output type is not 'snapshot' or an 'agent': '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_name)
					{
						if(strcmp("Ant", buffer) == 0) current_FLAME_output->type = 1;
						else if(strcmp("Pheromone", buffer) == 0) current_FLAME_output->type = 2;
						else if(strcmp("Generator", buffer) == 0) current_FLAME_output->type = 3;
						else if(strcmp("FoodGenerator", buffer) == 0) current_FLAME_output->type = 4;
						else if(strcmp("Nest", buffer) == 0) current_FLAME_output->type = 5;
						else if(strcmp("Food", buffer) == 0) current_FLAME_output->type = 6;
						else 
						{
							printf("Error: output name is not an agent name: '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_format)
					{
						if(strcmp("xml", buffer) == 0) current_FLAME_output->format = 0;
						else
						{
							printf("Error: output format is unsupported: '%s'\n", buffer);
							exit(0);
						}
					}
					if(FLAME_in_location)
					{
						current_FLAME_output->location = (char *)malloc( (strlen(filelocation) + strlen(buffer) + 1) * sizeof(char));
						strcpy(current_FLAME_output->location, filelocation);
						strcat(current_FLAME_output->location, buffer);
					}
					if(FLAME_in_time)
					{
						if(FLAME_in_period) current_FLAME_output->period = atoi(buffer);
						if(FLAME_in_phase)  current_FLAME_output->phase = atoi(buffer);
					}
				}
			}
			/* Reset buffer */
			i = 0;
		}
		/* If in tag put read char into buffer */
		else if(in_tag)
		{
			buffer[i] = c;
			i++;
		}
		/* If in data read char into buffer */
		else
		{
			buffer[i] = c;
			i++;
		}
	}

	/* Close the file */
	fclose(file);

	/* Also try and read environment and agents from 0.xml */
	readEnvironmentXML(filename);
	readAgentXML(filename, cloud_data, partition_method, flag, number_partitions, agent_count);

	/* If outputs is empty add default snapshot for every iteration */
	if(FLAME_outputs == NULL)
	{
		current_FLAME_output = add_FLAME_output(&FLAME_outputs);
		current_FLAME_output->type   = 0; /* snapshot */
		current_FLAME_output->format = 0; /* xml */
		current_FLAME_output->location = (char *)malloc( (strlen(filelocation) +  1) * sizeof(char));
		strcpy(current_FLAME_output->location, filelocation); /* location = 0.xml location */
		current_FLAME_output->period = 1; /* every iteration */
		current_FLAME_output->phase  = 0; /* no phase */
	}
	
	/* Print output settings to CLI */
	for(current_FLAME_output = FLAME_outputs; current_FLAME_output != NULL; current_FLAME_output = current_FLAME_output->next)
	{
		printf("output: type='");
		if(current_FLAME_output->type == 0) printf("snapshot");
		else if(current_FLAME_output->type == 1) printf("agent' name='Ant");
		else if(current_FLAME_output->type == 2) printf("agent' name='Pheromone");
		else if(current_FLAME_output->type == 3) printf("agent' name='Generator");
		else if(current_FLAME_output->type == 4) printf("agent' name='FoodGenerator");
		else if(current_FLAME_output->type == 5) printf("agent' name='Nest");
		else if(current_FLAME_output->type == 6) printf("agent' name='Food");
		else printf("undefined");
		printf("' format='");
		if(current_FLAME_output->format == 0) printf("xml");
		else printf("undefined");
		printf("' location='%s'", current_FLAME_output->location);
		printf(" period='%d' phase='%d'\n", current_FLAME_output->period, current_FLAME_output->phase);
	}

	/* Make sure cloud data makes sense if any of x,y,z coords were all the same */
	if ( partition_method == geometric ) {
		if ( cloud_data[0] == cloud_data[1] ) {
			cloud_data[0] = -SPINF;
			cloud_data[1] = SPINF;
		}
		if ( cloud_data[2] == cloud_data[3] ) {
			cloud_data[2] = -SPINF;
			cloud_data[3] = SPINF;
		}
		if ( cloud_data[4] == cloud_data[5] ) {
			cloud_data[4] = -SPINF;
			cloud_data[5] = SPINF;
		}
	}
}

/** \fn void write_int_static_array(FILE *file, $name * temp)
 * \brief Writes int.
 */
void write_int_static_array(FILE *file, int * temp, int size)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%i", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_static_array(FILE *file, float * temp)
 * \brief Writes float.
 */
void write_float_static_array(FILE *file, float * temp, int size)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%f", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_static_array(FILE *file, double * temp)
 * \brief Writes double.
 */
void write_double_static_array(FILE *file, double * temp, int size)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%f", temp[i]);
		fputs(data, file);
		if(i < size-1) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_static_array(FILE *file, char * temp)
 * \brief Writes char.
 */
void write_char_static_array(FILE *file, char * temp, int size)
{
	int i;
	char data[1000];

	//fputs("{", file);
	for(i=0; i<size; i++)
	{
		sprintf(data, "%c", temp[i]);
		fputs(data, file);
		//if(i < size-1) fputs(", ", file);
	}
	//fputs("}", file);
}

/** \fn void write_int_dynamic_array(FILE *file, int_array* temp)
 * \brief Writes int.
 */
void write_int_dynamic_array(FILE *file, int_array * temp)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%i", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_float_dynamic_array(FILE *file, float_array* temp)
 * \brief Writes float.
 */
void write_float_dynamic_array(FILE *file, float_array * temp)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%f", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_double_dynamic_array(FILE *file, double_array* temp)
 * \brief Writes double.
 */
void write_double_dynamic_array(FILE *file, double_array * temp)
{
	int i;
	char data[1000];

	fputs("{", file);
	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%f", (*temp).array[i]);
		fputs(data, file);
		if(i < ((*temp).size-1)) fputs(", ", file);
	}
	fputs("}", file);
}

/** \fn void write_char_dynamic_array(FILE *file, char_array* temp)
 * \brief Writes char.
 */
void write_char_dynamic_array(FILE *file, char_array * temp)
{
	int i;
	char data[1000];

	for(i=0; i<(*temp).size; i++)
	{
		sprintf(data, "%c", (*temp).array[i]);
		fputs(data, file);
	}
}



void write_Ant_agent(FILE *file, xmachine_memory_Ant * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Ant</name>\n", file);
		fputs("<antID>", file);
	sprintf(data, "%i", current->antID);
	fputs(data, file);
	fputs("</antID>\n", file);
		fputs("<antX>", file);
	sprintf(data, "%f", current->antX);
	fputs(data, file);
	fputs("</antX>\n", file);
		fputs("<antY>", file);
	sprintf(data, "%f", current->antY);
	fputs(data, file);
	fputs("</antY>\n", file);
		fputs("<foodLevel>", file);
	sprintf(data, "%f", current->foodLevel);
	fputs(data, file);
	fputs("</foodLevel>\n", file);
		fputs("<isFed>", file);
	sprintf(data, "%i", current->isFed);
	fputs(data, file);
	fputs("</isFed>\n", file);
		fputs("<isInNest>", file);
	sprintf(data, "%i", current->isInNest);
	fputs(data, file);
	fputs("</isInNest>\n", file);
		fputs("<antDirection>", file);
	sprintf(data, "%i", current->antDirection);
	fputs(data, file);
	fputs("</antDirection>\n", file);
		fputs("<state>", file);
	sprintf(data, "%i", current->state);
	fputs(data, file);
	fputs("</state>\n", file);

	fputs("</xagent>\n", file);
}

void write_Pheromone_agent(FILE *file, xmachine_memory_Pheromone * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Pheromone</name>\n", file);
		fputs("<pheromoneID>", file);
	sprintf(data, "%i", current->pheromoneID);
	fputs(data, file);
	fputs("</pheromoneID>\n", file);
		fputs("<life>", file);
	sprintf(data, "%f", current->life);
	fputs(data, file);
	fputs("</life>\n", file);
		fputs("<pheromoneX>", file);
	sprintf(data, "%f", current->pheromoneX);
	fputs(data, file);
	fputs("</pheromoneX>\n", file);
		fputs("<pheromoneY>", file);
	sprintf(data, "%f", current->pheromoneY);
	fputs(data, file);
	fputs("</pheromoneY>\n", file);

	fputs("</xagent>\n", file);
}

void write_Generator_agent(FILE *file, xmachine_memory_Generator * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Generator</name>\n", file);
		fputs("<memoryID>", file);
	sprintf(data, "%i", current->memoryID);
	fputs(data, file);
	fputs("</memoryID>\n", file);

	fputs("</xagent>\n", file);
}

void write_FoodGenerator_agent(FILE *file, xmachine_memory_FoodGenerator * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>FoodGenerator</name>\n", file);
		fputs("<memoryFoodID>", file);
	sprintf(data, "%i", current->memoryFoodID);
	fputs(data, file);
	fputs("</memoryFoodID>\n", file);

	fputs("</xagent>\n", file);
}

void write_Nest_agent(FILE *file, xmachine_memory_Nest * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Nest</name>\n", file);
		fputs("<nestX>", file);
	sprintf(data, "%f", current->nestX);
	fputs(data, file);
	fputs("</nestX>\n", file);
		fputs("<nestY>", file);
	sprintf(data, "%f", current->nestY);
	fputs(data, file);
	fputs("</nestY>\n", file);
		fputs("<nestRadius>", file);
	sprintf(data, "%f", current->nestRadius);
	fputs(data, file);
	fputs("</nestRadius>\n", file);

	fputs("</xagent>\n", file);
}

void write_Food_agent(FILE *file, xmachine_memory_Food * current)
{
	char data[1000];
	fputs("<xagent>\n" , file);
	fputs("<name>Food</name>\n", file);
		fputs("<foodID>", file);
	sprintf(data, "%i", current->foodID);
	fputs(data, file);
	fputs("</foodID>\n", file);
		fputs("<size>", file);
	sprintf(data, "%f", current->size);
	fputs(data, file);
	fputs("</size>\n", file);
		fputs("<foodX>", file);
	sprintf(data, "%f", current->foodX);
	fputs(data, file);
	fputs("</foodX>\n", file);
		fputs("<foodY>", file);
	sprintf(data, "%f", current->foodY);
	fputs(data, file);
	fputs("</foodY>\n", file);
		fputs("<radius>", file);
	sprintf(data, "%f", current->radius);
	fputs(data, file);
	fputs("</radius>\n", file);

	fputs("</xagent>\n", file);
}


void FLAME_write_xml(char * location, int iteration_number, int output_type)
{
	/* Pointer to file */
	FILE *file;
	char data[1000];

		sprintf(data, "%s%i.xml", location, iteration_number);
	
	if((file = fopen(data, "w"))==NULL)
	{
		printf("Error: cannot open file '%s' for writing\n", data);
		exit(0);
	}
	
	/*printf("xml file written: '%s' it=%d type=%d\n", data, iteration_number, output_type);*/
	
	
	fputs("<states>\n", file);
	if(output_type == 0)
	{
		fputs("<itno>", file);
		sprintf(data, "%i", iteration_number);
		fputs(data, file);
		fputs("</itno>\n", file);
		fputs("<environment>\n" , file);
			fputs("</environment>\n" , file);
	}
	
	
	if(output_type == 0 || output_type == 1)
	{
		
		current_xmachine_Ant_holder = Ant_05_state->agents;
			while(current_xmachine_Ant_holder)
			{
				write_Ant_agent(file, current_xmachine_Ant_holder->agent);

				current_xmachine_Ant_holder = current_xmachine_Ant_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 2)
	{
		
		current_xmachine_Pheromone_holder = Pheromone_03_state->agents;
			while(current_xmachine_Pheromone_holder)
			{
				write_Pheromone_agent(file, current_xmachine_Pheromone_holder->agent);

				current_xmachine_Pheromone_holder = current_xmachine_Pheromone_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 3)
	{
		
		current_xmachine_Generator_holder = Generator_01_state->agents;
			while(current_xmachine_Generator_holder)
			{
				write_Generator_agent(file, current_xmachine_Generator_holder->agent);

				current_xmachine_Generator_holder = current_xmachine_Generator_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 4)
	{
		
		current_xmachine_FoodGenerator_holder = FoodGenerator_01_state->agents;
			while(current_xmachine_FoodGenerator_holder)
			{
				write_FoodGenerator_agent(file, current_xmachine_FoodGenerator_holder->agent);

				current_xmachine_FoodGenerator_holder = current_xmachine_FoodGenerator_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 5)
	{
		
		current_xmachine_Nest_holder = Nest_01_state->agents;
			while(current_xmachine_Nest_holder)
			{
				write_Nest_agent(file, current_xmachine_Nest_holder->agent);

				current_xmachine_Nest_holder = current_xmachine_Nest_holder->next;
			}
		
	}
	
	if(output_type == 0 || output_type == 6)
	{
		
		current_xmachine_Food_holder = Food_02_state->agents;
			while(current_xmachine_Food_holder)
			{
				write_Food_agent(file, current_xmachine_Food_holder->agent);

				current_xmachine_Food_holder = current_xmachine_Food_holder->next;
			}
		
	}
	
	fputs("</states>\n" , file);

	/* Close the file */
	fclose(file);
}

/** \fn void saveiterationdata(int iteration_number)
 * \brief Save X-machine memory to a file.
 * \param iteration_number The current iteration number.
 */
void saveiterationdata(int iteration_number)
{
	FLAME_output * current_FLAME_output;
	FLAME_output * current_FLAME_output2;
	int flag;
	char * snapshot_location = NULL;

	/* First check snapshot */
	for(current_FLAME_output = FLAME_outputs; current_FLAME_output != NULL; current_FLAME_output = current_FLAME_output->next)
	{
		if(iteration_number%current_FLAME_output->period == current_FLAME_output->phase)
		{
			if(current_FLAME_output->type == 0)
			{
				snapshot_location = current_FLAME_output->location;
				FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
			}
			if(current_FLAME_output->type == 1)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 2)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 3)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 4)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 5)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			if(current_FLAME_output->type == 6)
			{
				/* If there has been a snapshot and location same as agent location then ignore */
				flag = 1;
				for(current_FLAME_output2 = FLAME_outputs; current_FLAME_output2 != NULL; current_FLAME_output2 = current_FLAME_output2->next)
				{
					if(current_FLAME_output2->type == 0 && strcmp(current_FLAME_output->location, current_FLAME_output2->location) == 0)
					{
						if(iteration_number%current_FLAME_output2->period == current_FLAME_output2->phase) flag = 0;
					}
				}
				
				if(flag==1)
				{
					FLAME_write_xml(current_FLAME_output->location, iteration_number, current_FLAME_output->type);
				}
			}
			
		}
	}
}
