/**
 * \file  messageboards.c
 * \brief Holds message board functions.
 */

#include "header.h"


/** \fn void add_pheromoneInformation_message(int pheromoneID, double pheromoneX, double pheromoneY, double life)
 * \brief Add pheromoneInformation message by calling internal and processing.
 * \param pheromoneID Message variable.
 * \param pheromoneX Message variable.
 * \param pheromoneY Message variable.
 * \param life Message variable.
 */
void add_pheromoneInformation_message(int pheromoneID, double pheromoneX, double pheromoneY, double life)
{
    int rc;
	m_pheromoneInformation msg;
    
    msg.pheromoneID = pheromoneID;
    msg.pheromoneX = pheromoneX;
    msg.pheromoneY = pheromoneY;
    msg.life = life;
    
    
    rc = MB_AddMessage(b_pheromoneInformation, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'pheromoneInformation' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pheromoneInformation' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pheromoneInformation' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_pheromoneInformation* getInternalMessage_pheromoneInformation(void)
{
    static m_pheromoneInformation *msg_prev = NULL;
    m_pheromoneInformation *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_pheromoneInformation); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'pheromoneInformation' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'pheromoneInformation' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_pheromoneInformation, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'pheromoneInformation' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pheromoneInformation' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_pheromoneInformation * get_first_pheromoneInformation_message()
 * \brief Get the first pheromoneInformation message in the pheromoneInformation message list.
 * \return The first message in the list.
 */
m_pheromoneInformation * get_first_pheromoneInformation_message()
{
	return getInternalMessage_pheromoneInformation();
}

/** \fn xmachine_message_pheromoneInformation * get_next_pheromoneInformation_message(xmachine_message_pheromoneInformation * current)
 * \brief Get the next pheromoneInformation message in the pheromoneInformation message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_pheromoneInformation * get_next_pheromoneInformation_message(m_pheromoneInformation * current)
{
	return getInternalMessage_pheromoneInformation();
}

/** \fn void add_newPheromoneInput_message(double pheromoneX, double pheromoneY)
 * \brief Add newPheromoneInput message by calling internal and processing.
 * \param pheromoneX Message variable.
 * \param pheromoneY Message variable.
 */
void add_newPheromoneInput_message(double pheromoneX, double pheromoneY)
{
    int rc;
	m_newPheromoneInput msg;
    
    msg.pheromoneX = pheromoneX;
    msg.pheromoneY = pheromoneY;
    
    
    rc = MB_AddMessage(b_newPheromoneInput, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'newPheromoneInput' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'newPheromoneInput' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'newPheromoneInput' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_newPheromoneInput* getInternalMessage_newPheromoneInput(void)
{
    static m_newPheromoneInput *msg_prev = NULL;
    m_newPheromoneInput *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_newPheromoneInput); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'newPheromoneInput' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'newPheromoneInput' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_newPheromoneInput, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'newPheromoneInput' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'newPheromoneInput' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_newPheromoneInput * get_first_newPheromoneInput_message()
 * \brief Get the first newPheromoneInput message in the newPheromoneInput message list.
 * \return The first message in the list.
 */
m_newPheromoneInput * get_first_newPheromoneInput_message()
{
	return getInternalMessage_newPheromoneInput();
}

/** \fn xmachine_message_newPheromoneInput * get_next_newPheromoneInput_message(xmachine_message_newPheromoneInput * current)
 * \brief Get the next newPheromoneInput message in the newPheromoneInput message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_newPheromoneInput * get_next_newPheromoneInput_message(m_newPheromoneInput * current)
{
	return getInternalMessage_newPheromoneInput();
}

/** \fn void add_foodInformation_message(int foodID, double foodX, double foodY, double size, double radius)
 * \brief Add foodInformation message by calling internal and processing.
 * \param foodID Message variable.
 * \param foodX Message variable.
 * \param foodY Message variable.
 * \param size Message variable.
 * \param radius Message variable.
 */
void add_foodInformation_message(int foodID, double foodX, double foodY, double size, double radius)
{
    int rc;
	m_foodInformation msg;
    
    msg.foodID = foodID;
    msg.foodX = foodX;
    msg.foodY = foodY;
    msg.size = size;
    msg.radius = radius;
    
    
    rc = MB_AddMessage(b_foodInformation, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'foodInformation' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foodInformation' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'foodInformation' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_foodInformation* getInternalMessage_foodInformation(void)
{
    static m_foodInformation *msg_prev = NULL;
    m_foodInformation *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_foodInformation); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'foodInformation' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'foodInformation' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_foodInformation, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'foodInformation' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foodInformation' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_foodInformation * get_first_foodInformation_message()
 * \brief Get the first foodInformation message in the foodInformation message list.
 * \return The first message in the list.
 */
m_foodInformation * get_first_foodInformation_message()
{
	return getInternalMessage_foodInformation();
}

/** \fn xmachine_message_foodInformation * get_next_foodInformation_message(xmachine_message_foodInformation * current)
 * \brief Get the next foodInformation message in the foodInformation message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_foodInformation * get_next_foodInformation_message(m_foodInformation * current)
{
	return getInternalMessage_foodInformation();
}

/** \fn void add_foodEaten_message(int id, double size)
 * \brief Add foodEaten message by calling internal and processing.
 * \param id Message variable.
 * \param size Message variable.
 */
void add_foodEaten_message(int id, double size)
{
    int rc;
	m_foodEaten msg;
    
    msg.id = id;
    msg.size = size;
    
    
    rc = MB_AddMessage(b_foodEaten, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'foodEaten' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foodEaten' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'foodEaten' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_foodEaten* getInternalMessage_foodEaten(void)
{
    static m_foodEaten *msg_prev = NULL;
    m_foodEaten *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_foodEaten); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'foodEaten' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'foodEaten' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_foodEaten, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'foodEaten' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'foodEaten' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_foodEaten * get_first_foodEaten_message()
 * \brief Get the first foodEaten message in the foodEaten message list.
 * \return The first message in the list.
 */
m_foodEaten * get_first_foodEaten_message()
{
	return getInternalMessage_foodEaten();
}

/** \fn xmachine_message_foodEaten * get_next_foodEaten_message(xmachine_message_foodEaten * current)
 * \brief Get the next foodEaten message in the foodEaten message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_foodEaten * get_next_foodEaten_message(m_foodEaten * current)
{
	return getInternalMessage_foodEaten();
}

/** \fn void add_newFood_message(double size, double foodX, double foodY, double radius)
 * \brief Add newFood message by calling internal and processing.
 * \param size Message variable.
 * \param foodX Message variable.
 * \param foodY Message variable.
 * \param radius Message variable.
 */
void add_newFood_message(double size, double foodX, double foodY, double radius)
{
    int rc;
	m_newFood msg;
    
    msg.size = size;
    msg.foodX = foodX;
    msg.foodY = foodY;
    msg.radius = radius;
    
    
    rc = MB_AddMessage(b_newFood, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'newFood' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'newFood' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'newFood' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_newFood* getInternalMessage_newFood(void)
{
    static m_newFood *msg_prev = NULL;
    m_newFood *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_newFood); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'newFood' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'newFood' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_newFood, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'newFood' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'newFood' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_newFood * get_first_newFood_message()
 * \brief Get the first newFood message in the newFood message list.
 * \return The first message in the list.
 */
m_newFood * get_first_newFood_message()
{
	return getInternalMessage_newFood();
}

/** \fn xmachine_message_newFood * get_next_newFood_message(xmachine_message_newFood * current)
 * \brief Get the next newFood message in the newFood message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_newFood * get_next_newFood_message(m_newFood * current)
{
	return getInternalMessage_newFood();
}

/** \fn void add_pheromoneIncreased_message(int pheromoneID, double increase)
 * \brief Add pheromoneIncreased message by calling internal and processing.
 * \param pheromoneID Message variable.
 * \param increase Message variable.
 */
void add_pheromoneIncreased_message(int pheromoneID, double increase)
{
    int rc;
	m_pheromoneIncreased msg;
    
    msg.pheromoneID = pheromoneID;
    msg.increase = increase;
    
    
    rc = MB_AddMessage(b_pheromoneIncreased, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'pheromoneIncreased' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pheromoneIncreased' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'pheromoneIncreased' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_pheromoneIncreased* getInternalMessage_pheromoneIncreased(void)
{
    static m_pheromoneIncreased *msg_prev = NULL;
    m_pheromoneIncreased *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_pheromoneIncreased); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'pheromoneIncreased' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'pheromoneIncreased' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_pheromoneIncreased, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'pheromoneIncreased' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'pheromoneIncreased' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_pheromoneIncreased * get_first_pheromoneIncreased_message()
 * \brief Get the first pheromoneIncreased message in the pheromoneIncreased message list.
 * \return The first message in the list.
 */
m_pheromoneIncreased * get_first_pheromoneIncreased_message()
{
	return getInternalMessage_pheromoneIncreased();
}

/** \fn xmachine_message_pheromoneIncreased * get_next_pheromoneIncreased_message(xmachine_message_pheromoneIncreased * current)
 * \brief Get the next pheromoneIncreased message in the pheromoneIncreased message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_pheromoneIncreased * get_next_pheromoneIncreased_message(m_pheromoneIncreased * current)
{
	return getInternalMessage_pheromoneIncreased();
}

/** \fn void add_nestInformation_message(double nestX, double nestY, double nestRadius)
 * \brief Add nestInformation message by calling internal and processing.
 * \param nestX Message variable.
 * \param nestY Message variable.
 * \param nestRadius Message variable.
 */
void add_nestInformation_message(double nestX, double nestY, double nestRadius)
{
    int rc;
	m_nestInformation msg;
    
    msg.nestX = nestX;
    msg.nestY = nestY;
    msg.nestRadius = nestRadius;
    
    
    rc = MB_AddMessage(b_nestInformation, &msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not add message to 'nestInformation' board\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'nestInformation' board has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
           case MB_ERR_LOCKED:
               fprintf(stderr, "\t reason: 'nestInformation' board is locked\n");
               break;
           case MB_ERR_INTERNAL:
               fprintf(stderr, "\t reason: internal error. Recompile libmoard in debug mode for more info \n");
               break;
	       default:
               fprintf(stderr, "\t MB_AddMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	   }
	      
	   
       exit(rc);
    }
    #endif
}

inline static m_nestInformation* getInternalMessage_nestInformation(void)
{
    static m_nestInformation *msg_prev = NULL;
    m_nestInformation *msg;
    int rc;
    
    /* deallocate previously returned message */
    if (msg_prev != NULL) 
    {
        free(msg_prev);
    }
    else 
    {
        rc = MB_Iterator_Rewind(i_nestInformation); 
        #ifdef ERRCHECK
        if (rc != MB_SUCCESS)
        {
            fprintf(stderr, "ERROR: Could not rewind 'nestInformation' Iterator\n");
            switch(rc) {
                case MB_ERR_INVALID:
                    fprintf(stderr, "\t reason: 'nestInformation' Iterator has not been created?\n");
                    break;
	            default:
                    fprintf(stderr, "\t MB_Iterator_Rewind returned error code: %d (see libmboard docs for details)\n", rc);
                    break;
	        }
	       
	       
       	   exit(rc);
        }
        #endif
    }
    
    /* get next message from iterator */
    rc = MB_Iterator_GetMessage(i_nestInformation, (void **)&msg);
    #ifdef ERRCHECK
    if (rc != MB_SUCCESS)
    {
       fprintf(stderr, "ERROR: Could not get message from 'nestInformation' Iterator\n");
       switch(rc) {
           case MB_ERR_INVALID:
               fprintf(stderr, "\t reason: 'nestInformation' Iterator has not been created?\n");
               break;
           case MB_ERR_MEMALLOC:
               fprintf(stderr, "\t reason: out of memory\n");
               break;
	       default:
               fprintf(stderr, "\t MB_Iterator_GetMessage returned error code: %d (see libmboard docs for details)\n", rc);
               break;
	       }
	       
	       
       	   exit(rc);
    }
    #endif
    
    /* store pointer so memory can be deallocated later */
    msg_prev = msg;
    
    return msg;
}

/** \fn xmachine_message_nestInformation * get_first_nestInformation_message()
 * \brief Get the first nestInformation message in the nestInformation message list.
 * \return The first message in the list.
 */
m_nestInformation * get_first_nestInformation_message()
{
	return getInternalMessage_nestInformation();
}

/** \fn xmachine_message_nestInformation * get_next_nestInformation_message(xmachine_message_nestInformation * current)
 * \brief Get the next nestInformation message in the nestInformation message list after the current message.
 * \param current The current message in the list.
 * \return The next message in the list.
 */
m_nestInformation * get_next_nestInformation_message(m_nestInformation * current)
{
	return getInternalMessage_nestInformation();
}

