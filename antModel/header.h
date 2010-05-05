/**
 * \file  header.h
 * \brief Header for xmachine data structures and transition functions.
 */

#ifdef _DEBUG_MODE
    #define ERRCHECK
#else
    #define NDEBUG
#endif

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include "mboard.h"

#define FLAME_TEST_PRINT_START_AND_END_OF_MODEL_FUNCTIONS 0
#define FLAME_TEST_PRINT_START_AND_END_OF_LIBMBOARD_CALLS 0
#define FLAME_USE_FILTERS_IN_SYNC 0


/* Checking macros */
#ifdef CHECK_MEMORY
#define CHECK_POINTER(PT) if(PT==NULL){printf("**** ERROR in Memory check 1\n");exit(1);}
#else
#define CHECK_POINTER(PT)
#endif


/** \def ARRAY_BLOCK_SIZE
 * \brief The block size to allocate to dynamic arrays. */
#define ARRAY_BLOCK_SIZE 5
/** \def START_PHEROMONEINFORMATION_MESSAGE_LOOP
 * \brief Start of loop to process pheromoneInformation messages. */
#define START_PHEROMONEINFORMATION_MESSAGE_LOOP  pheromoneInformation_message = get_first_pheromoneInformation_message(); while(pheromoneInformation_message) {
/** \def FINISH_PHEROMONEINFORMATION_MESSAGE_LOOP
 * \brief Finish of loop to process pheromoneInformation messages. */
#define FINISH_PHEROMONEINFORMATION_MESSAGE_LOOP pheromoneInformation_message = get_next_pheromoneInformation_message(pheromoneInformation_message); }
/** \def START_NEWPHEROMONEINPUT_MESSAGE_LOOP
 * \brief Start of loop to process newPheromoneInput messages. */
#define START_NEWPHEROMONEINPUT_MESSAGE_LOOP  newPheromoneInput_message = get_first_newPheromoneInput_message(); while(newPheromoneInput_message) {
/** \def FINISH_NEWPHEROMONEINPUT_MESSAGE_LOOP
 * \brief Finish of loop to process newPheromoneInput messages. */
#define FINISH_NEWPHEROMONEINPUT_MESSAGE_LOOP newPheromoneInput_message = get_next_newPheromoneInput_message(newPheromoneInput_message); }
/** \def START_FOODINFORMATION_MESSAGE_LOOP
 * \brief Start of loop to process foodInformation messages. */
#define START_FOODINFORMATION_MESSAGE_LOOP  foodInformation_message = get_first_foodInformation_message(); while(foodInformation_message) {
/** \def FINISH_FOODINFORMATION_MESSAGE_LOOP
 * \brief Finish of loop to process foodInformation messages. */
#define FINISH_FOODINFORMATION_MESSAGE_LOOP foodInformation_message = get_next_foodInformation_message(foodInformation_message); }
/** \def START_FOODEATEN_MESSAGE_LOOP
 * \brief Start of loop to process foodEaten messages. */
#define START_FOODEATEN_MESSAGE_LOOP  foodEaten_message = get_first_foodEaten_message(); while(foodEaten_message) {
/** \def FINISH_FOODEATEN_MESSAGE_LOOP
 * \brief Finish of loop to process foodEaten messages. */
#define FINISH_FOODEATEN_MESSAGE_LOOP foodEaten_message = get_next_foodEaten_message(foodEaten_message); }
/** \def START_NEWFOOD_MESSAGE_LOOP
 * \brief Start of loop to process newFood messages. */
#define START_NEWFOOD_MESSAGE_LOOP  newFood_message = get_first_newFood_message(); while(newFood_message) {
/** \def FINISH_NEWFOOD_MESSAGE_LOOP
 * \brief Finish of loop to process newFood messages. */
#define FINISH_NEWFOOD_MESSAGE_LOOP newFood_message = get_next_newFood_message(newFood_message); }
/** \def START_PHEROMONEINCREASED_MESSAGE_LOOP
 * \brief Start of loop to process pheromoneIncreased messages. */
#define START_PHEROMONEINCREASED_MESSAGE_LOOP  pheromoneIncreased_message = get_first_pheromoneIncreased_message(); while(pheromoneIncreased_message) {
/** \def FINISH_PHEROMONEINCREASED_MESSAGE_LOOP
 * \brief Finish of loop to process pheromoneIncreased messages. */
#define FINISH_PHEROMONEINCREASED_MESSAGE_LOOP pheromoneIncreased_message = get_next_pheromoneIncreased_message(pheromoneIncreased_message); }
/** \def START_NESTINFORMATION_MESSAGE_LOOP
 * \brief Start of loop to process nestInformation messages. */
#define START_NESTINFORMATION_MESSAGE_LOOP  nestInformation_message = get_first_nestInformation_message(); while(nestInformation_message) {
/** \def FINISH_NESTINFORMATION_MESSAGE_LOOP
 * \brief Finish of loop to process nestInformation messages. */
#define FINISH_NESTINFORMATION_MESSAGE_LOOP nestInformation_message = get_next_nestInformation_message(nestInformation_message); }


struct FLAME_output
{
	int type; /* 0=snapshot 1=Ant 2=Pheromone 3=Generator 4=FoodGenerator 5=Nest 6=Food */
	int format; /* 0=XML */
	char * location;
	int period;
	int phase;

	struct FLAME_output * next;
};
typedef struct FLAME_output FLAME_output;

/** \struct int_array
 * \brief Dynamic array to hold integers.
 *
 * Holds a pointer to an integer array and values for size and memory size.
 */
struct int_array
{
	int size;
	int total_size;

	int * array;
};

/** \struct float_array
 * \brief Dynamic array to hold floats.
 *
 * Holds a pointer to an float array and values for size and memory size.
 */
struct float_array
{
	int size;
	int total_size;

	float * array;
};

/** \struct double_array
 * \brief Dynamic array to hold doubles.
 *
 * Holds a pointer to a double array and values for size and memory size.
 */
struct double_array
{
	int size;
	int total_size;

	double * array;
};

/** \struct char_array
 * \brief Dynamic array to hold chars.
 *
 * Holds a pointer to a char array and values for size and memory size.
 */
struct char_array
{
	int size;
	int total_size;

	char * array;
};

/** \typedef struct int_array int_array
 * \brief Typedef for int_array struct.
 */
typedef struct int_array int_array;
/** \typedef struct float_array float_array
 * \brief Typedef for float_array struct.
 */
typedef struct float_array float_array;
/** \typedef struct double_array double_array
 * \brief Typedef for double_array struct.
 */
typedef struct double_array double_array;
/** \typedef struct char_array char_array
 * \brief Typedef for char_array struct.
 */
typedef struct char_array char_array;


/** \struct xmachine_memory_Ant
 * \brief Holds memory of xmachine Ant.
 */
struct xmachine_memory_Ant
{
	int antID;	/**< X-machine memory variable antID of type int. */
	double antX;	/**< X-machine memory variable antX of type double. */
	double antY;	/**< X-machine memory variable antY of type double. */
	double foodLevel;	/**< X-machine memory variable foodLevel of type double. */
	int isFed;	/**< X-machine memory variable isFed of type int. */
	int isInNest;	/**< X-machine memory variable isInNest of type int. */
	int antDirection;	/**< X-machine memory variable antDirection of type int. */
	int state;	/**< X-machine memory variable state of type int. */
};

/** \struct xmachine_memory_Ant_holder
 * \brief Holds struct of memory of xmachine Ant.
 */
struct xmachine_memory_Ant_holder
{
	struct xmachine_memory_Ant * agent;	/**< Pointer to X-machine memory Ant. */

	struct xmachine_memory_Ant_holder * prev;	/**< Pointer to previous Ant agent in the list.  */
	struct xmachine_memory_Ant_holder * next;	/**< Pointer to next Ant agent in the list.  */
};

/** \struct xmachine_memory_Ant_holder
 * \brief Holds struct of memory of xmachine Ant.
 */
struct xmachine_memory_Ant_state
{
	struct xmachine_memory_Ant_holder * agents;	/**< Pointer to X-machine memory Ant. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Pheromone
 * \brief Holds memory of xmachine Pheromone.
 */
struct xmachine_memory_Pheromone
{
	int pheromoneID;	/**< X-machine memory variable pheromoneID of type int. */
	double life;	/**< X-machine memory variable life of type double. */
	double pheromoneX;	/**< X-machine memory variable pheromoneX of type double. */
	double pheromoneY;	/**< X-machine memory variable pheromoneY of type double. */
};

/** \struct xmachine_memory_Pheromone_holder
 * \brief Holds struct of memory of xmachine Pheromone.
 */
struct xmachine_memory_Pheromone_holder
{
	struct xmachine_memory_Pheromone * agent;	/**< Pointer to X-machine memory Pheromone. */

	struct xmachine_memory_Pheromone_holder * prev;	/**< Pointer to previous Pheromone agent in the list.  */
	struct xmachine_memory_Pheromone_holder * next;	/**< Pointer to next Pheromone agent in the list.  */
};

/** \struct xmachine_memory_Pheromone_holder
 * \brief Holds struct of memory of xmachine Pheromone.
 */
struct xmachine_memory_Pheromone_state
{
	struct xmachine_memory_Pheromone_holder * agents;	/**< Pointer to X-machine memory Pheromone. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Generator
 * \brief Holds memory of xmachine Generator.
 */
struct xmachine_memory_Generator
{
	int memoryID;	/**< X-machine memory variable memoryID of type int. */
};

/** \struct xmachine_memory_Generator_holder
 * \brief Holds struct of memory of xmachine Generator.
 */
struct xmachine_memory_Generator_holder
{
	struct xmachine_memory_Generator * agent;	/**< Pointer to X-machine memory Generator. */

	struct xmachine_memory_Generator_holder * prev;	/**< Pointer to previous Generator agent in the list.  */
	struct xmachine_memory_Generator_holder * next;	/**< Pointer to next Generator agent in the list.  */
};

/** \struct xmachine_memory_Generator_holder
 * \brief Holds struct of memory of xmachine Generator.
 */
struct xmachine_memory_Generator_state
{
	struct xmachine_memory_Generator_holder * agents;	/**< Pointer to X-machine memory Generator. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_FoodGenerator
 * \brief Holds memory of xmachine FoodGenerator.
 */
struct xmachine_memory_FoodGenerator
{
	int memoryFoodID;	/**< X-machine memory variable memoryFoodID of type int. */
};

/** \struct xmachine_memory_FoodGenerator_holder
 * \brief Holds struct of memory of xmachine FoodGenerator.
 */
struct xmachine_memory_FoodGenerator_holder
{
	struct xmachine_memory_FoodGenerator * agent;	/**< Pointer to X-machine memory FoodGenerator. */

	struct xmachine_memory_FoodGenerator_holder * prev;	/**< Pointer to previous FoodGenerator agent in the list.  */
	struct xmachine_memory_FoodGenerator_holder * next;	/**< Pointer to next FoodGenerator agent in the list.  */
};

/** \struct xmachine_memory_FoodGenerator_holder
 * \brief Holds struct of memory of xmachine FoodGenerator.
 */
struct xmachine_memory_FoodGenerator_state
{
	struct xmachine_memory_FoodGenerator_holder * agents;	/**< Pointer to X-machine memory FoodGenerator. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Nest
 * \brief Holds memory of xmachine Nest.
 */
struct xmachine_memory_Nest
{
	double nestX;	/**< X-machine memory variable nestX of type double. */
	double nestY;	/**< X-machine memory variable nestY of type double. */
	double nestRadius;	/**< X-machine memory variable nestRadius of type double. */
};

/** \struct xmachine_memory_Nest_holder
 * \brief Holds struct of memory of xmachine Nest.
 */
struct xmachine_memory_Nest_holder
{
	struct xmachine_memory_Nest * agent;	/**< Pointer to X-machine memory Nest. */

	struct xmachine_memory_Nest_holder * prev;	/**< Pointer to previous Nest agent in the list.  */
	struct xmachine_memory_Nest_holder * next;	/**< Pointer to next Nest agent in the list.  */
};

/** \struct xmachine_memory_Nest_holder
 * \brief Holds struct of memory of xmachine Nest.
 */
struct xmachine_memory_Nest_state
{
	struct xmachine_memory_Nest_holder * agents;	/**< Pointer to X-machine memory Nest. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine_memory_Food
 * \brief Holds memory of xmachine Food.
 */
struct xmachine_memory_Food
{
	int foodID;	/**< X-machine memory variable foodID of type int. */
	double size;	/**< X-machine memory variable size of type double. */
	double foodX;	/**< X-machine memory variable foodX of type double. */
	double foodY;	/**< X-machine memory variable foodY of type double. */
	double radius;	/**< X-machine memory variable radius of type double. */
};

/** \struct xmachine_memory_Food_holder
 * \brief Holds struct of memory of xmachine Food.
 */
struct xmachine_memory_Food_holder
{
	struct xmachine_memory_Food * agent;	/**< Pointer to X-machine memory Food. */

	struct xmachine_memory_Food_holder * prev;	/**< Pointer to previous Food agent in the list.  */
	struct xmachine_memory_Food_holder * next;	/**< Pointer to next Food agent in the list.  */
};

/** \struct xmachine_memory_Food_holder
 * \brief Holds struct of memory of xmachine Food.
 */
struct xmachine_memory_Food_state
{
	struct xmachine_memory_Food_holder * agents;	/**< Pointer to X-machine memory Food. */

	int count;	/**< Number of agents that were in this state.  */
};

/** \struct xmachine
 * \brief Holds xmachines.
 */
struct xmachine
{
	struct xmachine_memory_Ant * xmachine_Ant;	/**< Pointer to X-machine memory of type Ant.  */
	struct xmachine_memory_Pheromone * xmachine_Pheromone;	/**< Pointer to X-machine memory of type Pheromone.  */
	struct xmachine_memory_Generator * xmachine_Generator;	/**< Pointer to X-machine memory of type Generator.  */
	struct xmachine_memory_FoodGenerator * xmachine_FoodGenerator;	/**< Pointer to X-machine memory of type FoodGenerator.  */
	struct xmachine_memory_Nest * xmachine_Nest;	/**< Pointer to X-machine memory of type Nest.  */
	struct xmachine_memory_Food * xmachine_Food;	/**< Pointer to X-machine memory of type Food.  */

	//struct xmachine * prev;	/**< Pointer to previous X-machine in the list.  */
	//struct xmachine * next;	/**< Pointer to next X-machine in the list.  */
};

/** \var void* FLAME_m_pheromoneInformation_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_pheromoneInformation_composite_params;

/** \struct m_pheromoneInformation
 * \brief Holds message of type pheromoneInformation_message.
 */
struct m_pheromoneInformation
{
	int pheromoneID;	/**< Message memory variable pheromoneID of type int. */
	double pheromoneX;	/**< Message memory variable pheromoneX of type double. */
	double pheromoneY;	/**< Message memory variable pheromoneY of type double. */
	double life;	/**< Message memory variable life of type double. */
};

/** \var void* FLAME_m_newPheromoneInput_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_newPheromoneInput_composite_params;

/** \struct m_newPheromoneInput
 * \brief Holds message of type newPheromoneInput_message.
 */
struct m_newPheromoneInput
{
	double pheromoneX;	/**< Message memory variable pheromoneX of type double. */
	double pheromoneY;	/**< Message memory variable pheromoneY of type double. */
};

/** \var void* FLAME_m_foodInformation_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_foodInformation_composite_params;

/** \struct m_foodInformation
 * \brief Holds message of type foodInformation_message.
 */
struct m_foodInformation
{
	int foodID;	/**< Message memory variable foodID of type int. */
	double foodX;	/**< Message memory variable foodX of type double. */
	double foodY;	/**< Message memory variable foodY of type double. */
	double size;	/**< Message memory variable size of type double. */
	double radius;	/**< Message memory variable radius of type double. */
};

/** \var void* FLAME_m_foodEaten_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_foodEaten_composite_params;

/** \struct m_foodEaten
 * \brief Holds message of type foodEaten_message.
 */
struct m_foodEaten
{
	int id;	/**< Message memory variable id of type int. */
	double size;	/**< Message memory variable size of type double. */
};

/** \var void* FLAME_m_newFood_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_newFood_composite_params;

/** \struct m_newFood
 * \brief Holds message of type newFood_message.
 */
struct m_newFood
{
	double size;	/**< Message memory variable size of type double. */
	double foodX;	/**< Message memory variable foodX of type double. */
	double foodY;	/**< Message memory variable foodY of type double. */
	double radius;	/**< Message memory variable radius of type double. */
};

/** \var void* FLAME_m_pheromoneIncreased_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_pheromoneIncreased_composite_params;

/** \struct m_pheromoneIncreased
 * \brief Holds message of type pheromoneIncreased_message.
 */
struct m_pheromoneIncreased
{
	int pheromoneID;	/**< Message memory variable pheromoneID of type int. */
	double increase;	/**< Message memory variable increase of type double. */
};

/** \var void* FLAME_m_nestInformation_composite_params\n
 * \brief Pointer to message sync agent composite params */
void* FLAME_m_nestInformation_composite_params;

/** \struct m_nestInformation
 * \brief Holds message of type nestInformation_message.
 */
struct m_nestInformation
{
	double nestX;	/**< Message memory variable nestX of type double. */
	double nestY;	/**< Message memory variable nestY of type double. */
	double nestRadius;	/**< Message memory variable nestRadius of type double. */
};

/** \typedef struct xmachine xmachine
 * \brief Typedef for xmachine struct.
 */
typedef struct xmachine xmachine;
/** \var typedef xmachine_memory_Ant xmachine_memory_Ant
 * \brief Typedef for xmachine_memory_Ant struct.
 */
typedef struct xmachine_memory_Ant xmachine_memory_Ant;
/** \var typedef xmachine_memory_Ant xmachine_memory_Ant
 * \brief Typedef for xmachine_memory_Ant struct.
 */
typedef struct xmachine_memory_Ant_holder xmachine_memory_Ant_holder;
/** \var typedef xmachine_memory_Ant xmachine_memory_Ant
 * \brief Typedef for xmachine_memory_Ant struct.
 */
typedef struct xmachine_memory_Ant_state xmachine_memory_Ant_state;
/** \var typedef xmachine_memory_Pheromone xmachine_memory_Pheromone
 * \brief Typedef for xmachine_memory_Pheromone struct.
 */
typedef struct xmachine_memory_Pheromone xmachine_memory_Pheromone;
/** \var typedef xmachine_memory_Pheromone xmachine_memory_Pheromone
 * \brief Typedef for xmachine_memory_Pheromone struct.
 */
typedef struct xmachine_memory_Pheromone_holder xmachine_memory_Pheromone_holder;
/** \var typedef xmachine_memory_Pheromone xmachine_memory_Pheromone
 * \brief Typedef for xmachine_memory_Pheromone struct.
 */
typedef struct xmachine_memory_Pheromone_state xmachine_memory_Pheromone_state;
/** \var typedef xmachine_memory_Generator xmachine_memory_Generator
 * \brief Typedef for xmachine_memory_Generator struct.
 */
typedef struct xmachine_memory_Generator xmachine_memory_Generator;
/** \var typedef xmachine_memory_Generator xmachine_memory_Generator
 * \brief Typedef for xmachine_memory_Generator struct.
 */
typedef struct xmachine_memory_Generator_holder xmachine_memory_Generator_holder;
/** \var typedef xmachine_memory_Generator xmachine_memory_Generator
 * \brief Typedef for xmachine_memory_Generator struct.
 */
typedef struct xmachine_memory_Generator_state xmachine_memory_Generator_state;
/** \var typedef xmachine_memory_FoodGenerator xmachine_memory_FoodGenerator
 * \brief Typedef for xmachine_memory_FoodGenerator struct.
 */
typedef struct xmachine_memory_FoodGenerator xmachine_memory_FoodGenerator;
/** \var typedef xmachine_memory_FoodGenerator xmachine_memory_FoodGenerator
 * \brief Typedef for xmachine_memory_FoodGenerator struct.
 */
typedef struct xmachine_memory_FoodGenerator_holder xmachine_memory_FoodGenerator_holder;
/** \var typedef xmachine_memory_FoodGenerator xmachine_memory_FoodGenerator
 * \brief Typedef for xmachine_memory_FoodGenerator struct.
 */
typedef struct xmachine_memory_FoodGenerator_state xmachine_memory_FoodGenerator_state;
/** \var typedef xmachine_memory_Nest xmachine_memory_Nest
 * \brief Typedef for xmachine_memory_Nest struct.
 */
typedef struct xmachine_memory_Nest xmachine_memory_Nest;
/** \var typedef xmachine_memory_Nest xmachine_memory_Nest
 * \brief Typedef for xmachine_memory_Nest struct.
 */
typedef struct xmachine_memory_Nest_holder xmachine_memory_Nest_holder;
/** \var typedef xmachine_memory_Nest xmachine_memory_Nest
 * \brief Typedef for xmachine_memory_Nest struct.
 */
typedef struct xmachine_memory_Nest_state xmachine_memory_Nest_state;
/** \var typedef xmachine_memory_Food xmachine_memory_Food
 * \brief Typedef for xmachine_memory_Food struct.
 */
typedef struct xmachine_memory_Food xmachine_memory_Food;
/** \var typedef xmachine_memory_Food xmachine_memory_Food
 * \brief Typedef for xmachine_memory_Food struct.
 */
typedef struct xmachine_memory_Food_holder xmachine_memory_Food_holder;
/** \var typedef xmachine_memory_Food xmachine_memory_Food
 * \brief Typedef for xmachine_memory_Food struct.
 */
typedef struct xmachine_memory_Food_state xmachine_memory_Food_state;
/** \typedef m_pheromoneInformation m_pheromoneInformation
 * \brief Typedef for m_pheromoneInformation struct.
 */
typedef struct m_pheromoneInformation m_pheromoneInformation;

/** \typedef m_newPheromoneInput m_newPheromoneInput
 * \brief Typedef for m_newPheromoneInput struct.
 */
typedef struct m_newPheromoneInput m_newPheromoneInput;

/** \typedef m_foodInformation m_foodInformation
 * \brief Typedef for m_foodInformation struct.
 */
typedef struct m_foodInformation m_foodInformation;

/** \typedef m_foodEaten m_foodEaten
 * \brief Typedef for m_foodEaten struct.
 */
typedef struct m_foodEaten m_foodEaten;

/** \typedef m_newFood m_newFood
 * \brief Typedef for m_newFood struct.
 */
typedef struct m_newFood m_newFood;

/** \typedef m_pheromoneIncreased m_pheromoneIncreased
 * \brief Typedef for m_pheromoneIncreased struct.
 */
typedef struct m_pheromoneIncreased m_pheromoneIncreased;

/** \typedef m_nestInformation m_nestInformation
 * \brief Typedef for m_nestInformation struct.
 */
typedef struct m_nestInformation m_nestInformation;


/** \struct location
 * \brief Holds location for calculating space partitioning .
 */
struct location
{
	double point;		/**< Point on an axis. */

	struct location * next;	/**< Pointer to next location on the list. */
};

/** \struct node_information
 * \brief Holds node information .
 */
struct node_information
{
	int node_id;	/**< Node ID. */
	double partition_data[6];	/**< Defines bounding box. */
	int agents_in_halo;	/**< Number of agents in the halo region. */
	int agent_total;	/**< Total number of agents on the node. */
	struct xmachine * agents;	/**< Pointer to list of X-machines. */
	struct m_pheromoneInformation * pheromoneInformation_messages;	/**< Pointer to pheromoneInformation message list. */
	struct m_newPheromoneInput * newPheromoneInput_messages;	/**< Pointer to newPheromoneInput message list. */
	struct m_foodInformation * foodInformation_messages;	/**< Pointer to foodInformation message list. */
	struct m_foodEaten * foodEaten_messages;	/**< Pointer to foodEaten message list. */
	struct m_newFood * newFood_messages;	/**< Pointer to newFood message list. */
	struct m_pheromoneIncreased * pheromoneIncreased_messages;	/**< Pointer to pheromoneIncreased message list. */
	struct m_nestInformation * nestInformation_messages;	/**< Pointer to nestInformation message list. */

	struct node_information * next;	/**< Pointer to next node on the list. */
};


/** \typedef struct location location
 * \brief Typedef for location struct.
 */
typedef struct location location;
/** \typedef struct node_information node_information
 * \brief Typedef for node_information struct.
 */
typedef struct node_information node_information;

/** \var xmachine * temp_xmachine
* \brief Pointer to xmachine to initialise linked list. */
xmachine * temp_xmachine;

/** \var m_pheromoneInformation * temp_pheromoneInformation_message
* \brief Pointer to m_pheromoneInformation to initialise linked list. */
m_pheromoneInformation * temp_pheromoneInformation_message;
/** \var m_newPheromoneInput * temp_newPheromoneInput_message
* \brief Pointer to m_newPheromoneInput to initialise linked list. */
m_newPheromoneInput * temp_newPheromoneInput_message;
/** \var m_foodInformation * temp_foodInformation_message
* \brief Pointer to m_foodInformation to initialise linked list. */
m_foodInformation * temp_foodInformation_message;
/** \var m_foodEaten * temp_foodEaten_message
* \brief Pointer to m_foodEaten to initialise linked list. */
m_foodEaten * temp_foodEaten_message;
/** \var m_newFood * temp_newFood_message
* \brief Pointer to m_newFood to initialise linked list. */
m_newFood * temp_newFood_message;
/** \var m_pheromoneIncreased * temp_pheromoneIncreased_message
* \brief Pointer to m_pheromoneIncreased to initialise linked list. */
m_pheromoneIncreased * temp_pheromoneIncreased_message;
/** \var m_nestInformation * temp_nestInformation_message
* \brief Pointer to m_nestInformation to initialise linked list. */
m_nestInformation * temp_nestInformation_message;
/** \var node_information * temp_node_info
* \brief Pointer to node_information to initialise linked list. */
node_information * temp_node_info;
/** \var char outputpath[1000]
* \brief Output path for files. */
char outputpath[1000];
/** \var long total_time
* \brief Total time for the simulation run (in seconds) */
double total_time;
/** \var int total_messages
* \brief Total messages sent between nodes for the simulation run */
int total_messages;
/** \var int totalnodes
* \brief Number of nodes */
int totalnodes;
/** \var xmachine ** p_xmachine
* \brief Pointer to first pointer of x-machine memory list */
//xmachine ** p_xmachine;
/** \var xmachine * current_xmachine
* \brief Pointer to current x-machine memory that is being processed */
xmachine * current_xmachine;
/* Pointer to current $agent_name agent */
xmachine_memory_Ant * current_xmachine_Ant;
xmachine_memory_Ant_holder * temp_xmachine_Ant_holder;
xmachine_memory_Ant_holder * current_xmachine_Ant_holder;
xmachine_memory_Ant_state * current_xmachine_Ant_next_state; /* New agents added to this state */
/* Pointer to list of Ant agents in state 05 state */
//xmachine_memory_Ant * temp_xmachine_Ant_05;
xmachine_memory_Ant_state * Ant_05_state;
/* Pointer to list of Ant agents in state 03 state */
//xmachine_memory_Ant * temp_xmachine_Ant_03;
xmachine_memory_Ant_state * Ant_03_state;
/* Pointer to list of Ant agents in state 02 state */
//xmachine_memory_Ant * temp_xmachine_Ant_02;
xmachine_memory_Ant_state * Ant_02_state;
/* Pointer to list of Ant agents in state 04 state */
//xmachine_memory_Ant * temp_xmachine_Ant_04;
xmachine_memory_Ant_state * Ant_04_state;
/* Pointer to list of Ant agents in state 01 state */
//xmachine_memory_Ant * temp_xmachine_Ant_01;
xmachine_memory_Ant_state * Ant_01_state;
/* Pointer to list of Ant agents in state 00 state */
//xmachine_memory_Ant * temp_xmachine_Ant_00;
xmachine_memory_Ant_state * Ant_00_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Pheromone * current_xmachine_Pheromone;
xmachine_memory_Pheromone_holder * temp_xmachine_Pheromone_holder;
xmachine_memory_Pheromone_holder * current_xmachine_Pheromone_holder;
xmachine_memory_Pheromone_state * current_xmachine_Pheromone_next_state; /* New agents added to this state */
/* Pointer to list of Pheromone agents in state 03 state */
//xmachine_memory_Pheromone * temp_xmachine_Pheromone_03;
xmachine_memory_Pheromone_state * Pheromone_03_state;
/* Pointer to list of Pheromone agents in state 02 state */
//xmachine_memory_Pheromone * temp_xmachine_Pheromone_02;
xmachine_memory_Pheromone_state * Pheromone_02_state;
/* Pointer to list of Pheromone agents in state 01 state */
//xmachine_memory_Pheromone * temp_xmachine_Pheromone_01;
xmachine_memory_Pheromone_state * Pheromone_01_state;
/* Pointer to list of Pheromone agents in state 00 state */
//xmachine_memory_Pheromone * temp_xmachine_Pheromone_00;
xmachine_memory_Pheromone_state * Pheromone_00_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Generator * current_xmachine_Generator;
xmachine_memory_Generator_holder * temp_xmachine_Generator_holder;
xmachine_memory_Generator_holder * current_xmachine_Generator_holder;
xmachine_memory_Generator_state * current_xmachine_Generator_next_state; /* New agents added to this state */
/* Pointer to list of Generator agents in state 01 state */
//xmachine_memory_Generator * temp_xmachine_Generator_01;
xmachine_memory_Generator_state * Generator_01_state;
/* Pointer to list of Generator agents in state 00 state */
//xmachine_memory_Generator * temp_xmachine_Generator_00;
xmachine_memory_Generator_state * Generator_00_state;
/* Pointer to current $agent_name agent */
xmachine_memory_FoodGenerator * current_xmachine_FoodGenerator;
xmachine_memory_FoodGenerator_holder * temp_xmachine_FoodGenerator_holder;
xmachine_memory_FoodGenerator_holder * current_xmachine_FoodGenerator_holder;
xmachine_memory_FoodGenerator_state * current_xmachine_FoodGenerator_next_state; /* New agents added to this state */
/* Pointer to list of FoodGenerator agents in state 01 state */
//xmachine_memory_FoodGenerator * temp_xmachine_FoodGenerator_01;
xmachine_memory_FoodGenerator_state * FoodGenerator_01_state;
/* Pointer to list of FoodGenerator agents in state 00 state */
//xmachine_memory_FoodGenerator * temp_xmachine_FoodGenerator_00;
xmachine_memory_FoodGenerator_state * FoodGenerator_00_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Nest * current_xmachine_Nest;
xmachine_memory_Nest_holder * temp_xmachine_Nest_holder;
xmachine_memory_Nest_holder * current_xmachine_Nest_holder;
xmachine_memory_Nest_state * current_xmachine_Nest_next_state; /* New agents added to this state */
/* Pointer to list of Nest agents in state 01 state */
//xmachine_memory_Nest * temp_xmachine_Nest_01;
xmachine_memory_Nest_state * Nest_01_state;
/* Pointer to list of Nest agents in state 00 state */
//xmachine_memory_Nest * temp_xmachine_Nest_00;
xmachine_memory_Nest_state * Nest_00_state;
/* Pointer to current $agent_name agent */
xmachine_memory_Food * current_xmachine_Food;
xmachine_memory_Food_holder * temp_xmachine_Food_holder;
xmachine_memory_Food_holder * current_xmachine_Food_holder;
xmachine_memory_Food_state * current_xmachine_Food_next_state; /* New agents added to this state */
/* Pointer to list of Food agents in state 02 state */
//xmachine_memory_Food * temp_xmachine_Food_02;
xmachine_memory_Food_state * Food_02_state;
/* Pointer to list of Food agents in state 01 state */
//xmachine_memory_Food * temp_xmachine_Food_01;
xmachine_memory_Food_state * Food_01_state;
/* Pointer to list of Food agents in state 00 state */
//xmachine_memory_Food * temp_xmachine_Food_00;
xmachine_memory_Food_state * Food_00_state;


MBt_Board b_pheromoneInformation;
MBt_Iterator i_pheromoneInformation;

MBt_Board b_newPheromoneInput;
MBt_Iterator i_newPheromoneInput;

MBt_Board b_foodInformation;
MBt_Iterator i_foodInformation;

MBt_Board b_foodEaten;
MBt_Iterator i_foodEaten;

MBt_Board b_newFood;
MBt_Iterator i_newFood;

MBt_Board b_pheromoneIncreased;
MBt_Iterator i_pheromoneIncreased;

MBt_Board b_nestInformation;
MBt_Iterator i_nestInformation;


/** \var m_pheromoneInformation * pheromoneInformation_message
* \brief Pointer to message struct for looping through pheromoneInformation message list */
m_pheromoneInformation * pheromoneInformation_message;
/** \var m_newPheromoneInput * newPheromoneInput_message
* \brief Pointer to message struct for looping through newPheromoneInput message list */
m_newPheromoneInput * newPheromoneInput_message;
/** \var m_foodInformation * foodInformation_message
* \brief Pointer to message struct for looping through foodInformation message list */
m_foodInformation * foodInformation_message;
/** \var m_foodEaten * foodEaten_message
* \brief Pointer to message struct for looping through foodEaten message list */
m_foodEaten * foodEaten_message;
/** \var m_newFood * newFood_message
* \brief Pointer to message struct for looping through newFood message list */
m_newFood * newFood_message;
/** \var m_pheromoneIncreased * pheromoneIncreased_message
* \brief Pointer to message struct for looping through pheromoneIncreased message list */
m_pheromoneIncreased * pheromoneIncreased_message;
/** \var m_nestInformation * nestInformation_message
* \brief Pointer to message struct for looping through nestInformation message list */
m_nestInformation * nestInformation_message;
/** \var FLAME_output ** FLAME_outputs
* \brief Pointer to list of outputs */
FLAME_output * FLAME_outputs;
/** \var node_information * p_node_info
* \brief Pointer to first pointer of node list */
node_information ** p_node_info;
/** \var node_information * current_node
* \brief Pointer to current node */
node_information * current_node;

/** \var int iteration_loop
* \brief The current iteration number */
int iteration_loop;
/** \var int output_frequency
* \brief Frequency to output results */
int output_frequency;
/** \var int output_offset
* \brief Offset to output results */
int output_offset;

/** \def SPINF
* \brief Dummy inf value for space partition data. */
#define SPINF 999999.123456
/** \def RELEASE
* \brief Used to kill an agent via 'return RELEASE;'. */
#define RELEASE 1
/** \def kill_me_now
* \brief Used to kill an agent via 'kill_me_now'. */
#define kill_me_now return 1

void initialise_pointers(void);
void initialise_unit_testing(void);
FLAME_output * add_FLAME_output(FLAME_output ** outputs);
void free_FLAME_outputs(FLAME_output ** outputs);
void add_location(double point, location ** p_location);
void freelocations(location ** p_location);
void add_node(int node_id, double minx, double maxx, double miny, double maxy, double minz, double maxz);
void clean_up(int code);
void propagate_agents(void);
void propagate_messages_init(void);
void propagate_messages_complete(void);
void create_partitions(char * filename, int * itno);
void free_node_info(void);
void free_agent(void);
void freexmachines(void);
/* model datatypes */

void init_int_static_array(int * array, int size);
void init_int_array(int_array * array);
void reset_int_array(int_array * array);
void free_int_array(int_array * array);
void copy_int_array(int_array * from, int_array * to);
//void sort_int_array(int_array array);
//int quicksort_int(int array, int elements);
void add_int(int_array * array, int new_int);
void remove_int(int_array * array, int index);
void print_int_array(int_array * array);
void init_float_static_array(float * array, int size);
void init_float_array(float_array * array);
void reset_float_array(float_array * array);
void free_float_array(float_array * array);
void copy_float_array(float_array * from, float_array * to);
//void sort_float_array(float_array array);
//int quicksort_float(float array, int elements);
void add_float(float_array * array, float new_float);
void remove_float(float_array * array, int index);
void print_float_array(float_array * array);
void init_double_static_array(double* array, int size);
void init_double_array(double_array * array);
void reset_double_array(double_array * array);
void free_double_array(double_array * array);
void copy_double_array(double_array * from, double_array * to);
//void sort_double_array(double_array array);
//int quicksort_double(double array, int elements);
void add_double(double_array * array, double new_double);
void remove_double(double_array * array, int index);
void print_double_array(double_array * array);
void init_char_static_array(char * array, int size);
void init_char_array(char_array * array);
void reset_char_array(char_array * array);
void free_char_array(char_array * array);
void copy_char_array(char_array * from, char_array * to);
void add_char(char_array * array, char new_char);
void remove_char(char_array * array, int index);
char * copy_array_to_str(char_array * array);
void print_char_array(char_array * array);
int idle();
/* xml.c */
int read_int_static_array(char * buffer, int buffer_size, int * j, int * int_static_array, int size);
int read_float_static_array(char * buffer, int buffer_size, int * j, float * float_static_array, int size);
int read_double_static_array(char * buffer, int buffer_size, int * j, double * double_static_array, int size);
int read_char_static_array(char * buffer, int buffer_size, int * j, char * char_static_array, int size);
int read_int_dynamic_array(char * buffer, int buffer_size, int * j, int_array * int_dynamic_array);
int read_float_dynamic_array(char * buffer, int buffer_size, int * j, float_array * float_dynamic_array);
int read_double_dynamic_array(char * buffer, int buffer_size, int * j, double_array * double_dynamic_array);
int read_char_dynamic_array(char * buffer, int buffer_size, int * j, char_array * char_dynamic_array);


void readinitialstates(char * filename, char * filelocation, int * itno, double cloud_data[6],
					   int partition_method, int flag);
void saveiterationdata(int iteration_number);


xmachine_memory_Ant_state * init_Ant_state();
xmachine_memory_Ant * init_Ant_agent();
void free_Ant_agent(xmachine_memory_Ant_holder * tmp, xmachine_memory_Ant_state * state);
void transition_Ant_agent(xmachine_memory_Ant_holder * tmp, xmachine_memory_Ant_state * from_state, xmachine_memory_Ant_state * to_state);
void add_Ant_agent_internal(xmachine_memory_Ant * agent, xmachine_memory_Ant_state * state);
void add_Ant_agent(int antID, double antX, double antY, double foodLevel, int isFed, int isInNest, int antDirection, int state);
void unittest_init_Ant_agent();
void unittest_free_Ant_agent();
xmachine_memory_Pheromone_state * init_Pheromone_state();
xmachine_memory_Pheromone * init_Pheromone_agent();
void free_Pheromone_agent(xmachine_memory_Pheromone_holder * tmp, xmachine_memory_Pheromone_state * state);
void transition_Pheromone_agent(xmachine_memory_Pheromone_holder * tmp, xmachine_memory_Pheromone_state * from_state, xmachine_memory_Pheromone_state * to_state);
void add_Pheromone_agent_internal(xmachine_memory_Pheromone * agent, xmachine_memory_Pheromone_state * state);
void add_Pheromone_agent(int pheromoneID, double life, double pheromoneX, double pheromoneY);
void unittest_init_Pheromone_agent();
void unittest_free_Pheromone_agent();
xmachine_memory_Generator_state * init_Generator_state();
xmachine_memory_Generator * init_Generator_agent();
void free_Generator_agent(xmachine_memory_Generator_holder * tmp, xmachine_memory_Generator_state * state);
void transition_Generator_agent(xmachine_memory_Generator_holder * tmp, xmachine_memory_Generator_state * from_state, xmachine_memory_Generator_state * to_state);
void add_Generator_agent_internal(xmachine_memory_Generator * agent, xmachine_memory_Generator_state * state);
void add_Generator_agent(int memoryID);
void unittest_init_Generator_agent();
void unittest_free_Generator_agent();
xmachine_memory_FoodGenerator_state * init_FoodGenerator_state();
xmachine_memory_FoodGenerator * init_FoodGenerator_agent();
void free_FoodGenerator_agent(xmachine_memory_FoodGenerator_holder * tmp, xmachine_memory_FoodGenerator_state * state);
void transition_FoodGenerator_agent(xmachine_memory_FoodGenerator_holder * tmp, xmachine_memory_FoodGenerator_state * from_state, xmachine_memory_FoodGenerator_state * to_state);
void add_FoodGenerator_agent_internal(xmachine_memory_FoodGenerator * agent, xmachine_memory_FoodGenerator_state * state);
void add_FoodGenerator_agent(int memoryFoodID);
void unittest_init_FoodGenerator_agent();
void unittest_free_FoodGenerator_agent();
xmachine_memory_Nest_state * init_Nest_state();
xmachine_memory_Nest * init_Nest_agent();
void free_Nest_agent(xmachine_memory_Nest_holder * tmp, xmachine_memory_Nest_state * state);
void transition_Nest_agent(xmachine_memory_Nest_holder * tmp, xmachine_memory_Nest_state * from_state, xmachine_memory_Nest_state * to_state);
void add_Nest_agent_internal(xmachine_memory_Nest * agent, xmachine_memory_Nest_state * state);
void add_Nest_agent(double nestX, double nestY, double nestRadius);
void unittest_init_Nest_agent();
void unittest_free_Nest_agent();
xmachine_memory_Food_state * init_Food_state();
xmachine_memory_Food * init_Food_agent();
void free_Food_agent(xmachine_memory_Food_holder * tmp, xmachine_memory_Food_state * state);
void transition_Food_agent(xmachine_memory_Food_holder * tmp, xmachine_memory_Food_state * from_state, xmachine_memory_Food_state * to_state);
void add_Food_agent_internal(xmachine_memory_Food * agent, xmachine_memory_Food_state * state);
void add_Food_agent(int foodID, double size, double foodX, double foodY, double radius);
void unittest_init_Food_agent();
void unittest_free_Food_agent();

void add_pheromoneInformation_message(int pheromoneID, double pheromoneX, double pheromoneY, double life);
m_pheromoneInformation * add_pheromoneInformation_message_internal(void);
m_pheromoneInformation * get_first_pheromoneInformation_message(void);
m_pheromoneInformation * get_next_pheromoneInformation_message(m_pheromoneInformation * current);
void freepheromoneInformationmessages(void);

void add_newPheromoneInput_message(double pheromoneX, double pheromoneY);
m_newPheromoneInput * add_newPheromoneInput_message_internal(void);
m_newPheromoneInput * get_first_newPheromoneInput_message(void);
m_newPheromoneInput * get_next_newPheromoneInput_message(m_newPheromoneInput * current);
void freenewPheromoneInputmessages(void);

void add_foodInformation_message(int foodID, double foodX, double foodY, double size, double radius);
m_foodInformation * add_foodInformation_message_internal(void);
m_foodInformation * get_first_foodInformation_message(void);
m_foodInformation * get_next_foodInformation_message(m_foodInformation * current);
void freefoodInformationmessages(void);

void add_foodEaten_message(int id, double size);
m_foodEaten * add_foodEaten_message_internal(void);
m_foodEaten * get_first_foodEaten_message(void);
m_foodEaten * get_next_foodEaten_message(m_foodEaten * current);
void freefoodEatenmessages(void);

void add_newFood_message(double size, double foodX, double foodY, double radius);
m_newFood * add_newFood_message_internal(void);
m_newFood * get_first_newFood_message(void);
m_newFood * get_next_newFood_message(m_newFood * current);
void freenewFoodmessages(void);

void add_pheromoneIncreased_message(int pheromoneID, double increase);
m_pheromoneIncreased * add_pheromoneIncreased_message_internal(void);
m_pheromoneIncreased * get_first_pheromoneIncreased_message(void);
m_pheromoneIncreased * get_next_pheromoneIncreased_message(m_pheromoneIncreased * current);
void freepheromoneIncreasedmessages(void);

void add_nestInformation_message(double nestX, double nestY, double nestRadius);
m_nestInformation * add_nestInformation_message_internal(void);
m_nestInformation * get_first_nestInformation_message(void);
m_nestInformation * get_next_nestInformation_message(m_nestInformation * current);
void freenestInformationmessages(void);


void set_antID(int antID);
int get_antID();
void set_antX(double antX);
double get_antX();
void set_antY(double antY);
double get_antY();
void set_foodLevel(double foodLevel);
double get_foodLevel();
void set_isFed(int isFed);
int get_isFed();
void set_isInNest(int isInNest);
int get_isInNest();
void set_antDirection(int antDirection);
int get_antDirection();
void set_state(int state);
int get_state();
void set_pheromoneID(int pheromoneID);
int get_pheromoneID();
void set_life(double life);
double get_life();
void set_pheromoneX(double pheromoneX);
double get_pheromoneX();
void set_pheromoneY(double pheromoneY);
double get_pheromoneY();
void set_memoryID(int memoryID);
int get_memoryID();
void set_memoryFoodID(int memoryFoodID);
int get_memoryFoodID();
void set_nestX(double nestX);
double get_nestX();
void set_nestY(double nestY);
double get_nestY();
void set_nestRadius(double nestRadius);
double get_nestRadius();
void set_foodID(int foodID);
int get_foodID();
void set_size(double size);
double get_size();
void set_foodX(double foodX);
double get_foodX();
void set_foodY(double foodY);
double get_foodY();
void set_radius(double radius);
double get_radius();
int agent_get_id(void);
double agent_get_x(void);
double agent_get_y(void);
double agent_get_z(void);
/* partitioning.c */
void partition_data(int totalnodes, xmachine ** agent_list, double cloud_data[6], int partition_method);


void save_partition_data(void);
void generate_partitions(double cloud_data[6], int partitions, int partition_method);

/* messageboard.c */
m_pheromoneInformation * get_next_message_pheromoneInformation_in_range(m_pheromoneInformation * current);
m_newPheromoneInput * get_next_message_newPheromoneInput_in_range(m_newPheromoneInput * current);
m_foodInformation * get_next_message_foodInformation_in_range(m_foodInformation * current);
m_foodEaten * get_next_message_foodEaten_in_range(m_foodEaten * current);
m_newFood * get_next_message_newFood_in_range(m_newFood * current);
m_pheromoneIncreased * get_next_message_pheromoneIncreased_in_range(m_pheromoneIncreased * current);
m_nestInformation * get_next_message_nestInformation_in_range(m_nestInformation * current);

/* memory.c */
xmachine * add_xmachine(void);


/* rules.c */
int FLAME_integer_in_array(int a, int * b, int size);

/* timing.c */
double get_time(void);

int updateState(void);
int stayInNest(void);
int FLAME_condition_Ant_stayInNest_01_04(xmachine_memory_Ant *a);
int walk(void);
int FLAME_condition_Ant_walk_01_02(xmachine_memory_Ant *a);
int deposit(void);
int FLAME_condition_Ant_deposit_02_03(xmachine_memory_Ant *a);
int depositIdle(void);
int FLAME_condition_Ant_depositIdle_02_04(xmachine_memory_Ant *a);
int forage(void);
int FLAME_condition_Ant_forage_03_04(xmachine_memory_Ant *a);
int forageIdle(void);
int FLAME_condition_Ant_forageIdle_03_04(xmachine_memory_Ant *a);
int decreaseFoodLevel(void);
int findNest(void);
int FLAME_condition_Ant_findNest_01_02(xmachine_memory_Ant *a);
int pheromoneInformation(void);
int decreasePheromoneLife(void);
int increasePheromoneLife(void);
int produce(void);
int produceFood(void);
int nestInformation(void);
int foodInformation(void);
int updateFood(void);
