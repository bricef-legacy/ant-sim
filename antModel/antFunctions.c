#include "header.h"
#include "Ant_agent_header.h"
#include "Pheromone_agent_header.h"
#include "Generator_agent_header.h"
#include "Food_agent_header.h"
#include "FoodGenerator_agent_header.h"
#include "Nest_agent_header.h"

#define xLeftBorder 20.0
#define xRightBorder 300.0
#define yUpperBorder 20.0
#define yLowerBorder 300.0

#define antStepSize 3.0
#define antPheromoneSmellDistance 3.0
#define antMinPheromoneDetectionUnit 0.2
#define antFoodLevelDecay 0.02
#define antFoodFound 100
#define antPheromoneDepositionUnit 2.0

#define minPheromoneDistance 1.0
#define pheromoneDecay 0.0248

#define stateWalk 1
#define stateFindNest 2
#define stateStayInNest 0

struct Data {
    int maxIndex;
    double information1[1000];
    double information2[1000];
};

struct PheromoneData {
    double pheromoneX;
    double pheromoneY;
    double pheromoneLife;
    int direction;
};

/*enum STATE {FORAGING, IDLE, TO_NEST} cur_state;*/

int getDirection(double, double, double, double);

double getDistance(double x, double y, double tx, double ty) {
    return sqrt(pow(tx - x, 2) + pow(ty - y, 2));
}

//Handles environment boundary for y-axis border
double checkAntPositionY(double antPosition) {
    double newPosition = antPosition;

    if (antPosition < yUpperBorder) {
        newPosition = yUpperBorder;
    }

    if (antPosition > yLowerBorder) {
        newPosition = yLowerBorder;
    }
    return newPosition;
}

//Handles environment boundary for x-axis border
double checkAntPositionX(double antPosition) {
    double newPosition = antPosition;

    if (antPosition < xLeftBorder) {
        newPosition = xLeftBorder;
    }

    if (antPosition > xRightBorder) {
        newPosition = xRightBorder;
    }
    return newPosition;
}

//Calculates the direction from between two coordinates
int getDirection(double aX, double aY, double tX, double tY) {

    double tmp = aY;
    aY = tY;
    tY = tmp;

    double vx = tX - aX;
    double vy = tY - aY;

    double length = sqrt((vx * vx) + (vy * vy));
    double alpha = acos(vy / length) * (180.0 / 3.142);

    if (vx < 0) {
        alpha = 360 - alpha;
    }

    int result = (int) round(alpha / 360 * 8);
    if (result == 0) {
        return 8;
    }
    return result;
}

//Updates the position based on current coordinates and direction provided
void updatePosition(double* aX, double* aY, int direction) {

    double b = sqrt(antStepSize * antStepSize / 2.0);
    switch (direction) {
    case 8:
        *aY -= antStepSize;
        break;
    case 4:
        *aY += antStepSize;
        break;
    case 1:
        *aX += b;
        *aY -= b;
        break;
    case 2:
        *aX += antStepSize;
        break;
    case 3:
        *aX += b;
        *aY += b;
        break;
    case 5:
        *aX -= b;
        *aY += b;
        break;
    case 6:
        *aX -= antStepSize;
        break;
    case 7:
        *aX -= b;
        *aY -= b;
        break;
    default:
        break;
    }
}

//Calculates a new direction based on current direction and angle provided
int getNewDirection(int currentDir, double angle) {
    double vx = 0;
    double vy = 0;

    switch (currentDir) {
    case 8:
        vy = 1;
        break;
    case 4:
        vy = -1;
        break;
    case 1:
        vx = 1;
        vy = 1;
        break;
    case 2:
        vx = 1;
        break;
    case 3:
        vx = 1;
        vy = -1;
        break;
    case 5:
        vx = -1;
        vy = -1;
        break;
    case 6:
        vx = -1;
        break;
    case 7:
        vx = -1;
        vy = 1;
        break;
    default:
        break;
    }

    double length = sqrt((vx * vx) + (vy * vy));
    double alpha = acos(vy / length) * (180.0 / 3.142);

    if (vx < 0) {
        alpha = 360 - alpha;
    }

    double totalAngle = alpha + angle;
    if (totalAngle > 360) {
        totalAngle -= 360;
    }
    if (totalAngle < 0) {
        totalAngle += 360;
    }

    int result = (int) round(totalAngle / 360 * 8);
    if (result == 0) {
        return 8;
    }
    return result;
}

//Detects a pheromone within ant pheromone smell range
int detectPheromone(double* pheromoneX, double* pheromoneY) {

    double pheromoneLife = -1;

    double currentX = ANTX;
    double currentY = ANTY;

    int direction = ANTDIRECTION;
    int nextdir = (direction + 1) > 8 ? 1 : direction + 1;
    int prevdir = (direction - 1) < 1 ? 8 : direction - 1;

    pheromoneInformation_message = get_first_pheromoneInformation_message();
    double distanceToPheromone = 0;

    double randomNumber1 = ((double) rand() / ((double) RAND_MAX)); //0 and 1

    //leaving trail probability
    if (randomNumber1 <= 0.001){
        pheromoneLife = -1;
        *pheromoneX = -1;
        *pheromoneY = -1;
    } else {
        while (pheromoneInformation_message) {
            double pheromoneLocalX = pheromoneInformation_message->pheromoneX;
            double pheromoneLocalY = pheromoneInformation_message->pheromoneY;
            double pheromoneLocalLife = pheromoneInformation_message->life;

            distanceToPheromone = getDistance(pheromoneLocalX, pheromoneLocalY, currentX, currentY);

            if (distanceToPheromone <= antPheromoneSmellDistance && pheromoneLocalLife >= antMinPheromoneDetectionUnit && distanceToPheromone > minPheromoneDistance) {
                int newDirection = getDirection(ANTX, ANTY, pheromoneLocalX, pheromoneLocalY);
                if (newDirection == direction || newDirection == nextdir || newDirection == prevdir) {
                    if (pheromoneLife <= pheromoneLocalLife) {
                        pheromoneLife = pheromoneLocalLife;
                        *pheromoneX = pheromoneLocalX;
                        *pheromoneY = pheromoneLocalY;
                    }
                }
            }
            pheromoneInformation_message = get_next_pheromoneInformation_message(pheromoneInformation_message);
        }
    }
    return 0;
}

//Chooses a new direction at random and updates current position accordingly
int walkRandomly() {

    double currentX = ANTX;
    double currentY = ANTY;
    double newX = currentX;
    double newY = currentY;
    double randomDirection = ((double) rand() / ((double) RAND_MAX)) * 8 + 1; //0 and 8

    updatePosition(&newX, &newY, randomDirection);
    ANTY = checkAntPositionY(newY);
    ANTX = checkAntPositionX(newX);
    ANTDIRECTION = randomDirection;

    return 0;
}

//Updates state of the ant
int updateState(){

    if ((ISINNEST == 1 && FOODLEVEL < 1.0) || (ISFED == 0 && FOODLEVEL < 1.0)) {
        STATE = stateWalk;
    } else if (ISFED == 1 && ISINNEST != 1) {
        STATE = stateFindNest;
    } else if (ISINNEST == 1 && FOODLEVEL >= 1.0) {
        STATE = stateStayInNest;
    } else {
        //printf("this should never happen!\n");
    }
    return 0;
}

//Idle functions
int stayInNest(){
    return 0;
}

int forageIdle(){
    return 0;
}

int depositIdle(){
    return 0;
}

//Ant agent walk function
int walk() {

    double pheromoneX = -1;
    double pheromoneY = -1;

    ISINNEST = 0;

    detectPheromone(&pheromoneX, &pheromoneY);

    //no pheromones nearby
    if (pheromoneX == -1 && pheromoneY == -1) {
        walkRandomly();
    } else {
        //pheromone found
            double currentX = ANTX;
            double currentY = ANTY;
            int direction = getDirection(ANTX, ANTY, pheromoneX, pheromoneY);
            updatePosition(&currentX, &currentY, direction);
            ANTX = checkAntPositionX(currentX);
            ANTY = checkAntPositionY(currentY);
            ANTDIRECTION = direction;
    }
    return 0;
}

//Ant agent
//decrease foodLevel at each iteration
int decreaseFoodLevel() {
    FOODLEVEL = FOODLEVEL - antFoodLevelDecay;

    if (FOODLEVEL <= 0) {
        FOODLEVEL = 0;
    }

    if (FOODLEVEL <1.0 && ISFED!=0){
        ISFED = 0;
    }

    return 0;
}

//Ant agent
//find a food source and eat 0.2 units
int forage() {

    int localId;

    foodInformation_message = get_first_foodInformation_message();
    while (foodInformation_message) {
        double xFood = foodInformation_message->foodX;
        double yFood = foodInformation_message->foodY;
        double foodRadius = foodInformation_message->radius;
        double foodConc = foodInformation_message->concentration;
        double distanceToFood = getDistance(xFood, yFood, ANTX, ANTY);

        if (distanceToFood <= foodRadius + 2) {
            LASTFOODCONC=foodConc;
            double foodSize = foodInformation_message->size;
            localId = foodInformation_message->foodID;
            FOODLEVEL = FOODLEVEL + antFoodFound;
            ISFED = 1;
            add_foodEaten_message(localId, (foodSize - 0.2));
            int direction = ANTDIRECTION;
            ANTDIRECTION = getNewDirection(direction, 180);
            return 0;
        }
        foodInformation_message = get_next_foodInformation_message(foodInformation_message);
    }
    return 0;
}


//FoodGenerator agent
//creates a new food agent dynamically by checking newFood_message
int produceFood() {
    newFood_message = get_first_newFood_message();
    while (newFood_message) {
        double x = newFood_message->foodX;
        double y = newFood_message->foodY;
        double foodSize = newFood_message->size;
        double foodRadius = newFood_message->radius;

        MEMORYFOODID++;
        printf("foodCounter %d\n",MEMORYFOODID);
        add_Food_agent(MEMORYFOODID, foodSize, x, y, foodRadius, 0.0); //Arbitrary concentration, we should never need to produce new foods
        newFood_message = get_next_newFood_message(newFood_message);
    }

    return 0;
}

//Food agent
//if one of the food sources is depleted, create newFood_message
//which is passed to produceFood() function for FoodGenerator agent
int updateFood() {
    foodEaten_message = get_first_foodEaten_message();
    while (foodEaten_message) {
        int localID = foodEaten_message->id;
        if (localID == FOODID) {
            SIZE = foodEaten_message->size;
            if (SIZE <= 0.2) {

                //printf("creating new food\n");
                double xPosition = rand() / (double) (RAND_MAX) * 280;
                double yPosition = rand() / (double) (RAND_MAX) * 280;

                SIZE = (rand() / (double) (RAND_MAX) * 100) + 1;

                if (SIZE > 0 && SIZE < 5) {
                    RADIUS = 5.0;
                } else if (SIZE >= 5 && SIZE < 10) {
                    RADIUS = 6.0;
                } else if (SIZE >= 10 && SIZE < 20) {
                    RADIUS = 7.0;
                } else if (SIZE >= 20 && SIZE < 30) {
                    RADIUS = 8.0;
                } else if (SIZE >= 30 && SIZE < 40) {
                    RADIUS = 9.0;
                } else if (SIZE >= 40 && SIZE < 50) {
                    RADIUS = 10.0;
                } else if (SIZE >= 50 && SIZE < 60) {
                    RADIUS = 11.0;
                } else if (SIZE >= 60 && SIZE < 70) {
                    RADIUS = 12.0;
                } else if (SIZE >= 70 && SIZE < 80) {
                    RADIUS = 13.0;
                } else if (SIZE >= 80 && SIZE < 90) {
                    RADIUS = 14.0;
                } else if (SIZE >= 90) {
                    RADIUS = 15.0;
                }

                add_newFood_message(SIZE, xPosition, yPosition, RADIUS);
                return 1;
            }
        }
        foodEaten_message = get_next_foodEaten_message(foodEaten_message);
    }
    return 0;
}

//Food agent
//add foodInfo
int foodInformation() {
    if (SIZE > 0 && SIZE < 5) {
        RADIUS = 5.0;
    } else if (SIZE >= 5 && SIZE < 10) {
        RADIUS = 6.0;
    } else if (SIZE >= 10 && SIZE < 20) {
        RADIUS = 7.0;
    } else if (SIZE >= 20 && SIZE < 30) {
        RADIUS = 8.0;
    } else if (SIZE >= 30 && SIZE < 40) {
        RADIUS = 9.0;
    } else if (SIZE >= 40 && SIZE < 50) {
        RADIUS = 10.0;
    } else if (SIZE >= 50 && SIZE < 60) {
        RADIUS = 11.0;
    } else if (SIZE >= 60 && SIZE < 70) {
        RADIUS = 12.0;
    } else if (SIZE >= 70 && SIZE < 80) {
        RADIUS = 13.0;
    } else if (SIZE >= 80 && SIZE < 90) {
        RADIUS = 14.0;
    } else if (SIZE >= 90) {
        RADIUS = 15.0;
    }

    add_foodInformation_message(FOODID, FOODX, FOODY, SIZE, RADIUS, CONCENTRATION);

    return 0;
}

//Nest agent
//add nestInfo
int nestInformation() {
    add_nestInformation_message(NESTX, NESTY, NESTRADIUS);

    return 0;
}

//Pheromone agent
//add pheromoneInfo
int pheromoneInformation() {
    add_pheromoneInformation_message(PHEROMONEID, PHEROMONEX, PHEROMONEY, LIFE);

    return 0;
}

//Ant agent
//deposit a pheromone at each step
//if a pheromone was previously deposited at a particular coordinate, increase pheromone level
//if not create a new one
int deposit() {
    pheromoneInformation_message = get_first_pheromoneInformation_message();
    int found = 0;
    while (pheromoneInformation_message && found == 0) {
        double distance = getDistance(ANTX, ANTY, pheromoneInformation_message->pheromoneX, pheromoneInformation_message->pheromoneY);
        if (distance > 0.3 && distance <= minPheromoneDistance) {
            found = 1;
            add_pheromoneIncreased_message(pheromoneInformation_message->pheromoneID, antPheromoneDepositionUnit*LASTFOODCONC);
        }
        pheromoneInformation_message = get_next_pheromoneInformation_message(pheromoneInformation_message);
    }
    if (found == 0) {
        add_newPheromoneInput_message(ANTX, ANTY, LASTFOODCONC);
        //TODO
    }
    return 0;
}

//Pheromone agent
//decrease pheromoneLife at each iteration
int decreasePheromoneLife() {
    if (LIFE >= 0.02) {
        LIFE = LIFE - (pheromoneDecay * LIFE);
    }
    if (LIFE < 0.02) { //pheromone evaporated
        return 1;
    }

    return 0;
}

//Pheromone agent
//increases the life of a previously deposited pheromone at a specific location
int increasePheromoneLife() {
    pheromoneIncreased_message = get_first_pheromoneIncreased_message();

    while (pheromoneIncreased_message) {
        int localPheromoneID = pheromoneIncreased_message->pheromoneID;

        if (localPheromoneID == PHEROMONEID) {
            LIFE = LIFE + pheromoneIncreased_message->increase;
        }

        pheromoneIncreased_message = get_next_pheromoneIncreased_message(pheromoneIncreased_message);
    }

    return 0;
}

//Generator agent
//produces a pheromone agent dynamically
//prevents duplicate deposition
int produce() {
    newPheromoneInput_message = get_first_newPheromoneInput_message();
    struct Data data;
    data.maxIndex = 0;
    while (newPheromoneInput_message) {
        double x = newPheromoneInput_message->pheromoneX;
        double y = newPheromoneInput_message->pheromoneY;
        double mult = newPheromoneInput_message->multiplier;
        
        int found = 0;
        for (int i = 0; i < data.maxIndex; i++) {
            if (data.information1[i] == x && data.information2[i] == y) {
                found = 1;
            }
        }
        if (found == 0) {
            data.information1[data.maxIndex] = x;
            data.information2[data.maxIndex] = y;
            data.maxIndex = data.maxIndex + 1;
        }
        newPheromoneInput_message = get_next_newPheromoneInput_message(newPheromoneInput_message);
    }

    for (int i = 0; i < data.maxIndex; i++) {
        MEMORYID++;
        add_Pheromone_agent(MEMORYID, antPheromoneDepositionUnit, data.information1[i], data.information2[i]);
    }
    return 0;
}

//Ant agent
//after eating food, ant agent goes back to nest
int findNest() {

        int pheromoneFound = 0;
        int epFound = 0;
        double currentX = ANTX;
        double currentY = ANTY;

        struct PheromoneData p;
        p.pheromoneX = -1;
        p.pheromoneY = -1;
        p.pheromoneLife = -1;
        p.direction = ANTDIRECTION;

        struct PheromoneData ep;
        ep.pheromoneX = -1;
        ep.pheromoneY = -1;
        ep.pheromoneLife = -1;
        ep.direction = ANTDIRECTION;

        int direction = ANTDIRECTION;

        int nextdir = (direction + 1) > 8 ? 1 : direction + 1;
        int prevdir = (direction - 1) < 1 ? 8 : direction - 1;
        int next2dir = (direction + 2) > 8 ? 1 : direction + 2;
        int prev2dir = (direction - 2) < 1 ? 8 : direction - 2;

        double distanceToPheromone = 0;

        nestInformation_message = get_first_nestInformation_message();
        while (nestInformation_message) {
            double xNest = nestInformation_message->nestX;
            double yNest = nestInformation_message->nestY;
            double nestRadius = nestInformation_message->nestRadius;

            double distanceToNest = getDistance(xNest, yNest, currentX, currentY);

            if (distanceToNest <= nestRadius + 2) {
                ISINNEST = 1;
                return 0;
            }
            nestInformation_message = get_next_nestInformation_message(nestInformation_message);
        }
        pheromoneInformation_message = get_first_pheromoneInformation_message();

        while (pheromoneInformation_message) {
            double pheromoneLocalX = pheromoneInformation_message->pheromoneX;
            double pheromoneLocalY = pheromoneInformation_message->pheromoneY;
            double pheromoneLocalLife = pheromoneInformation_message->life;
            distanceToPheromone = getDistance(pheromoneLocalX, pheromoneLocalY, currentX, currentY);

            if (distanceToPheromone <= antPheromoneSmellDistance && pheromoneLocalLife > antMinPheromoneDetectionUnit && distanceToPheromone > minPheromoneDistance) {
                int newDirection = getDirection(ANTX, ANTY, pheromoneLocalX, pheromoneLocalY);
                if (newDirection == direction || newDirection == nextdir || newDirection == prevdir) {
                    if (p.pheromoneLife <= pheromoneLocalLife) {
                        p.pheromoneLife = pheromoneLocalLife;
                        p.pheromoneX = pheromoneLocalX;
                        p.pheromoneY = pheromoneLocalY;
                        p.direction = getDirection(ANTX, ANTY, p.pheromoneX, p.pheromoneY);
                        pheromoneFound = 1;
                    }
                } else if (newDirection == next2dir || newDirection == prev2dir) {
                    if (ep.pheromoneLife <= pheromoneLocalLife) {
                        ep.pheromoneLife = pheromoneLocalLife;
                        ep.pheromoneX = pheromoneLocalX;
                        ep.pheromoneY = pheromoneLocalY;
                        ep.direction = getDirection(ANTX, ANTY, ep.pheromoneX, ep.pheromoneY);
                        epFound = 1;
                    }
                }
            }
            pheromoneInformation_message = get_next_pheromoneInformation_message(pheromoneInformation_message);
        }
        if (pheromoneFound == 1) {
            direction = p.direction;
            updatePosition(&currentX, &currentY, direction);
            ANTX = checkAntPositionX(currentX);
            ANTY = checkAntPositionY(currentY);
            ANTDIRECTION = direction;

        } else if (epFound == 1) {
            direction = ep.direction;
            updatePosition(&currentX, &currentY, direction);
            ANTX = checkAntPositionX(currentX);
            ANTY = checkAntPositionY(currentY);
            ANTDIRECTION = direction;

        } else {
            walkRandomly();
    }
    return 0;
}
