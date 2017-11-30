//Declare any variables shared between functions here
float vectorBetween[3];
float myState[12];
float rateTarget[3];
float targetRate[3];
float targetNoRate[3];
float distance;
float myPos[3];
float posA[2];
float posB[2];
float posC[2];
float posD[2];
float stop[3];
int step;

void init(){
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
	
	stop[0]= 0.0
	stop[1] = 0.0
	stop[2] = 0.0
	
	rateTarget[0]=0.0;
	rateTarget[1]=0.0;
	rateTarget[2]=35*PI/180;
	
	targetRate[0]=0.0;
    targetRate[1]=20*PI/180;
    targetRate[2]=0.0;
    
    targetNoRate[0]=0.0;
    targetNoRate[1]=-20*PI/180;
    targetNoRate[2]=0.0;
    
	step = 0;
}

void move_to(float position[2]){
	    api.getMyZRState(myState);
	        for (int i=0; i<3; i++){
	            myPos[i]=myState[i];
	        }
	        if ((myState[0] != position[0]) && (myState[1] != position[1]) && (myState[2] < position[2])) {
	            mathVecSubtract(vectorBetween,position,myPos,3);
	        	distance = mathVecMagnitude(vectorBetween,3);
	        	if (distance > 0.225){
	        	    api.setVelocityTarget(vectorBetween);
	        	}
	        	else {
	        	    api.setPositionTarget(position);
	        	}
	        }
	        else {
	            step++;
	        }
	    DEBUG (("distancia A = %f", distance));
}

void Drill(float position[2], int number){
	    api.getMyZRState(myState);
	    game.getDrills(myState);
	    api.setPositionTarget(position);
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
	    if (game.getNumSamplesHeld() == number){
	        api.setAttRateTarget(stop);
	    }
	    if ((myState[11] <= 0.1) && (game.getNumSamplesHeld() == number)){
	        game.stopDrill();
	        step++;
	    }
}

void loop(){
	switch (step){
		case 0:
			move_to(posA);
			break;
		case 1:
			Drill(posA,2);
			break;
		case 2:
			move_to(posB);
			break;
		case 3:
			Drill(posB,5)
			break; 
		case 4: 
			goto_BaseR(); 
			break; 
		case 5: 
			at_Base(); 
			break; 
		case 6: 
			move_to(posC); 
			break; 
		case 7: 
			Drill(posC, 2); 
			break; 
		case 8: 
			move_to(posD)
			break; 
		case 9: 
			Dril(posD, 5); 
			break; 
	}
}
