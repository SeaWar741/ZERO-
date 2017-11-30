//Begin page Azul 0: Pos A
void get_posA(){
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
        if ((myState[0] < posA[0]) && (myState[1] < posA[1]) && (myState[2] < posA[2])) {
            mathVecSubtract(vectorBetween,posA,myPos,3);
        	distance = mathVecMagnitude(vectorBetween,3);
        	if (distance > 0.225){
        	    api.setVelocityTarget(vectorBetween);
        	}
        	else {
        	    api.setPositionTarget(posA);
        	}
        }
        else {
            step++;
        }
    DEBUG (("distancia A = %f", distance));
}
//End page Azul 0: Pos A
//Begin page Azul 1: Drill A
void start_DrillingA(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    api.setPositionTarget(posA);
    if (game.getDrills(myState) <= 0){
        game.getDrillEnabled();
    }
    if (myState[11] >= stop[2]){
        game.startDrill();
        api.setAttRateTarget(rateTarget);
        game.checkSample();
    }
    if (game.checkSample()==true){
        game.pickupSample();
        game.getNumSamplesHeld();
    }
    if (game.getNumSamplesHeld() == 2){
        api.setAttRateTarget(stop);
    }
    if ((myState[11] <= 0.1) && (game.getNumSamplesHeld() == 2)){
        game.stopDrill();
        step++;
    }
}
//End page Azul 1: Drill A
//Begin page Azul 2: Pos B
void get_posB(){
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
        if (myState[0] < posB[0]) {
            mathVecSubtract(vectorBetween,posB,myPos,3);
        	distance = mathVecMagnitude(vectorBetween,3);
        	if (distance > 0.07){
        	   api.setVelocityTarget(vectorBetween);
        	}
        	else {
        	    api.setPositionTarget(posB);
        	}
        }
        else {
            step++;
        }
    DEBUG (("distancia B = %f", distance));
}
//End page Azul 2: Pos B
//Begin page Azul 3: Drill B
void start_DrillingB(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    api.setPositionTarget(posB);
    if (game.getDrills(myState) <= 0){
        game.getDrillEnabled();
    }
    if (myState[11] >= stop[2]){
        game.startDrill();
        api.setAttRateTarget(rateTarget);
        game.checkSample();
    }
    if (game.checkSample()==true){
        game.pickupSample();
        game.getNumSamplesHeld();
    }
    if (game.getNumSamplesHeld() == 5){
        api.setAttRateTarget(stop);
    }
    if ((myState[11] <= 0.2) && (game.getNumSamplesHeld() == 5)){
        game.stopDrill();
        api.setAttitudeTarget(targetAtt);
        step++;
    }
}
//End page Azul 3: Drill B
//Begin page Azul 4: Base R
/*void goto_BaseR(){
    spin_atBase();
    api.getMyZRState(myState);
        for (int l=0; l<3; l++){
            myPos[l]=myState[l];
        }
        mathVecSubtract(vectorBetween,basePosR,myPos,3);
        distance = mathVecMagnitude(vectorBetween,3);
        if (distance > 0.01){
            api.setPositionTarget(basePosR);
        }
        else if (distance <= 0.01) {
            api.setAttRateTarget(stop);
            step++;
        }
}*/
void goto_BaseR(){
    spin_atBase();
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
        if ((myState[0] > basePosR[0]) && (myState[1] > basePosR[1]) && (myState[2] > basePosR[2])) {
            mathVecSubtract(vectorBetween,basePosR,myPos,3);
        	distance = mathVecMagnitude(vectorBetween,3);
        	if (distance > 0.2675){
        	    api.setVelocityTarget(vectorBetween);
        	}
        	else {
        	    api.setPositionTarget(basePosR);
        	}
        }
        else {
            step++;
        }
    DEBUG (("Base State A = %f", distance));
}
//End page Azul 4: Base R
//Begin page Azul 5: At Base
void at_Base(){
    game.atBaseStation();
    game.getNumSamplesHeld();
    if (game.atBaseStation()==true){
        game.dropSample(0);
        game.dropSample(1);
        game.dropSample(2);
        game.dropSample(3);
        game.dropSample(4);
    }
    if (game.getNumSamplesHeld() == 0){
        step++;
    }
}
//End page Azul 5: At Base
//Begin page Azul 6: Pos C
void get_posC(){
    spin_atNoBase();
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
        if ((myState[0] < posC[0]) && (myState[1] < posC[1]) && (myState[2] < posC[2])) {
            mathVecSubtract(vectorBetween,posC,myPos,3);
        	distance = mathVecMagnitude(vectorBetween,3);
        	if (distance > 0.2){
        	   api.setVelocityTarget(vectorBetween);
        	}
        	else {
        	    api.setPositionTarget(posC);
        	}
        }
        else {
            step++;
        }
    DEBUG (("distancia C = %f", distance));
}
//End page Azul 6: Pos C
//Begin page Azul 7: Drill C
void start_DrillingC(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    api.setPositionTarget(posC);
    if (game.getDrills(myState) <= 0){
        game.getDrillEnabled();
    }
    if (myState[11] >= stop[2]){
        game.startDrill();
        api.setAttRateTarget(rateTarget);
        game.checkSample();
    }
    if (game.checkSample()==true){
        game.pickupSample();
        game.getNumSamplesHeld();
    }
    if (game.getNumSamplesHeld() == 2){
        api.setAttRateTarget(stop);
    }
    if ((myState[11] <= 0.1) && (game.getNumSamplesHeld() == 2)){
        game.stopDrill();
        step++;
    }
}
//End page Azul 7: Drill C
//Begin page Azul 8: Pos D
/*void get_posD(){
    api.getMyZRState(myState);
    api.setPositionTarget(posD);
    if (myState[0] < posD[0]){
        api.setPositionTarget(posD);
    }
    else {
        step++;
    }
    DEBUG (("distancia = %f", distance));
}*/

void get_posD(){
    api.setAttitudeTarget(targetAtt2);
    api.getMyZRState(myState);
        for (int i=0; i<3; i++){
            myPos[i]=myState[i];
        }
        if (myState[0] < posD[0]) {
            mathVecSubtract(vectorBetween,posD,myPos,3);
        	distance = mathVecMagnitude(vectorBetween,3);
        	if (distance > 0.07){
        	   api.setVelocityTarget(vectorBetween);
        	}
        	else {
        	    api.setPositionTarget(posD);
        	}
        }
        else {
            step++;
        }
    DEBUG (("distancia D = %f", distance));
}
//End page Azul 8: Pos D
//Begin page Azul 9: Drill D
void start_DrillingD(){
    api.getMyZRState(myState);
    game.getDrills(myState);
    api.setPositionTarget(posD);
    if (game.getDrills(myState) <= 0){
        game.getDrillEnabled();
    }
    if (myState[11] >= stop[2]){
        game.startDrill();
        api.setAttRateTarget(rateTarget);
        game.checkSample();
    }
    if (game.checkSample()==true){
        game.pickupSample();
        game.getNumSamplesHeld();
    }
    if (game.getNumSamplesHeld() == 5){
        api.setAttRateTarget(stop);
    }
    if ((myState[11] <= 0.1) && (game.getNumSamplesHeld() == 5)){
        game.stopDrill();
        step++;
    }
}
//End page Azul 9: Drill D
//Begin page Función 1: Spin Base
void spin_atBase(){
	api.getMyZRState(myState);
	for (int i=0; i<3; i++){
	    myAtt[i]=myState[i+6];
	    if (counter == 0){
	        initAtt[i]=myState[i+6];
	        api.setAttitudeTarget(targetAtt);
	    }
	}
	counter++;
    	dot=mathVecInner(initAtt,myAtt,3);
    	angle=acosf(dot)*180/PI;
    	DEBUG(("%f",angle));
    	if ((angle < 88) || (angle > 92)){
    	   api.setAttitudeTarget(attAtBase);
    	}
    	else {
    	    api.setAttRateTarget(stop);
    	}
}
//End page Función 1: Spin Base
//Begin page Función 2: Spin No Base
void spin_atNoBase(){
	api.getMyZRState(myState);
	for (int i=0; i<3; i++){
	    myAtt[i]=myState[i+6];
	    if (contador == 0){
	        initAtt[i]=myState[i+6];
	    }
	}
	contador++;
    	dot=mathVecInner(initAtt,myAtt,3);
    	angle=acosf(dot)*180/PI;
    	DEBUG(("%f",angle));
    	if (angle<50){
    	    api.setAttRateTarget(targetNoRate);
    	}
    	else if ((angle < 2) || (angle > -2)){
    	    api.setAttitudeTarget(targetAtt2);
    	}
    	else {
    	    api.setAttRateTarget(stop);
    	}
}
//End page Función 2: Spin No Base
//Begin page Función 3: Active Geyser
 void active_Geyser(){
     api.getMyZRState(myState);
     game.isGeyserHere(myState);
     if (game.isGeyserHere(myState) == true){
         game.stopDrill();
         //api.setForces(baseGeyser1);
     }
 }
//End page Función 3: Active Geyser
//Begin page Función 4: Drill Error
void drill_Error(){
    game.getDrillError();
    if (game.getDrillError() == true){
        game.stopDrill();
        step++;
    }
}
//End page Función 4: Drill Error
//Begin page Función 5: Rescate
void SOS(){
    api.getMyZRState(myState);
    if (myState[2] < -0.05){
        api.setPositionTarget(basePosR);
        api.setAttitudeTarget(targetAtt);
    }
}
//End page Función 5: Rescate
//Begin page main
//Declare any variables shared between functions here
float myState[12];
float myPos[3];
float basePosR[3];
float posA[3];
float posB[3];
float posC[3];
float posD[3];
float vectorBetween[3];
float stop[3];
float rateTarget[3];
float baseGeyser1[3];
int step;
float distance;
float initAtt[3];
float myAtt[3];
float targetRate[3];
float targetNoRate[3];
float dot;
float angle;
int counter; //ingles
int contador; //español
int zahler; //aleman
float targetAtt[3];
float targetAtt2[3];
float attAtBase[3];
float miPos[3];
float initPos[3];
float item[3];

void init(){
	//This function is called once when your code is first loaded.

	//IMPORTANT: make sure to set any variables that need an initial value.
	//Do not assume variables will be set to 0 automatically!
    posA[0]=0.25;
	posA[1]=0.25;
	posA[2]=0.36;
	posB[0]=0.35;
	posB[1]=0.25;
	posB[2]=0.36;
	
	posC[0]=0.15;
	posC[1]=0.15;
	posC[2]=0.36;
    posD[0]=0.25;
	posD[1]=0.15;
	posD[2]=0.36;
	
	
	basePosR[0]=0.1;
	basePosR[1]=0.1;
	basePosR[2]=0.1;
	
	stop[0]=0.0;
	stop[1]=0.0;
	stop[2]=0.0;
	
	targetAtt[0]=1;
	targetAtt[1]=0;
	targetAtt[2]=0;
	
	targetAtt2[0]=0;
	targetAtt2[1]=-1;
	targetAtt2[2]=0;
	
	attAtBase[0]=0; 
	attAtBase[1]=0;
	attAtBase[2]=-1;
	
	rateTarget[0]=0.0;
	rateTarget[1]=0.0;
	rateTarget[2]=35*PI/180;
	
	targetRate[0]=0.0;
    targetRate[1]=20*PI/180;
    targetRate[2]=0.0;
    
    targetNoRate[0]=0.0;
    targetNoRate[1]=-20*PI/180;
    targetNoRate[2]=0.0;
	
	baseGeyser1[0]=-10;
	baseGeyser1[1]=-10;
	baseGeyser1[2]=10;
	
	item[0]=0.0;
	item[1]=10.0;
	item[2]=0.0;
	
	step = 0;
	counter = 0;
	contador = 0;
	zahler = 0;
	
}


void loop(){
	//This function is called once per second.  Use it to control the satellite.
	SOS();
	drill_Error();
	active_Geyser();
	switch(step){
	    case 0:
	        get_posA();
	        break;
	    case 1:
	        start_DrillingA();
	        break;
	    case 2: 
	        get_posB(); 
	        break; 
	    case 3: 
	        start_DrillingB();
	        break;
        case 4:
            goto_BaseR();
            break;
        case 5:
            at_Base();
            break;
        case 6:
            get_posC();
            break;
        case 7:
            start_DrillingC();
            break;
        case 8:
            get_posD();
            break;
        case 9:
            start_DrillingD();
            break;
        case 10:
            goto_BaseR();
            break;
        case 11:
            at_Base();
            break;
	}
    DEBUG(("Step = %d",step));
    for(int i=0; i<12; i++){
        DEBUG(("State = %f", myState[i]));
    }
}

//End page main
