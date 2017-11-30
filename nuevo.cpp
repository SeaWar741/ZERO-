

//DEC VARIABLES 
    int step;
    float myPos[3];
    float posA[3];
    float posB[3];
    float posC[3];

    //RED
    float posA2[3];
    float posB2[3];
    float posC2[3];

    float vectorBetween[3];
    float distance;
    float rateTarget[3];
    float stop[3];
    float forces[3];
    float kp;
    float pos[12];
    float speed[3];

    // Constantes
    float kp = 0.3;
    float range = 0.01;

    // Params
    int step;


void init(){
    //CONSTANTES
    posA[0]=0.35;
    posA[1]=0.35;
    posA[2]=0.0;
    
    posB[0]=-0.35;
    posB[1]=0.35;
    posB[2]=0.0;
    
    posC[0]=0.15;
    posC[1]=0.15;
    posC[2]=0.0;

    //RED
    posA2[0]=-0.35;
    posA2[1]=-0.35;
    posA2[2]=0.0;
    
    posB2[0]=0.35;
    posB2[1]=-0.35;
    posB2[2]=0.0;
    
    posC2[0]=-0.15;
    posC2[1]=-0.15;
    posC2[2]=0.0;
}

float dist(float* a, float* b){
    return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2) + pow(a[2] - b[2], 2));
}

bool goTo(float* dest){
    api.getMyZRState(pos);
    int i = 0;
    for (i = 0; i < 3; i++) {
        float error = pos[i] - pos[i];
        speed[i] = kp * error;
    }
    api.setVelocityTarget(speed);
    return dist(pos, dest) < range;
}

void loop(){
	//This function is called once per second.  Use it to control the satellite.
	api.getMyZRState(myState);
    if (myState[1] > 0){
        switch (step){
            case 0:
                if (goTo(posA))
                {
                    step++;
                }
                break;
            case 1:
                if (game.startDrill())
                {
                    step++;
                }
                break;
            case 2:
                if (goTo(posB2))
                {
                   step++;
                }
                break;
            case 3: 
                if (game.startDrill())
                {
                    step++;
                }
                break;
            case 4:
                if (goTo(posC2))
                {
                    step++;
                }
                break;
        }
    }
    else {
        switch (step){
            case 0:
                ();
                break;
            case 1:
                ();
                break;
        }
    }
    DEBUG(("step = %d",step));

}

