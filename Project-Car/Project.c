/*---------------------------------------------------------------------------------------------------------
 * Created by Moustafa Ahmed Adel
 * Diploma Number 66
 * Eng. Mohamed Tarek ( First Project )
-----------------------------------------------------------------------------------------------------------*/
#include <stdio.h>
#include<string.h>
#include<math.h>

//--------------Typedef---------------
#define true 1
#define false 0
#define WITH_ENGINE_TEMP_CONTROLLER 1
//-----------------------------
char welcomeoptions, RandomOptions, Exit = 0;
//
//-----------------------------

// Creating System Status as a structure
typedef enum ENUM
{
	correct, incorrect
}ENUM;

struct status
{
	char Engine[4], AC[4], EngineTempController[4];
	int  Vspeed, Rtemp, Etemp;
}System;

// Printing System Status
void DisplayStatus()
{
	printf(" Engine is %s\n", System.Engine);
	printf(" AC is %s\n", System.AC);
	printf(" Vehicle speed is: %d Km/Hr\n", System.Vspeed);
	printf(" Room Temperature is: %d C\n", System.Rtemp);
#if WITH_ENGINE_TEMP_CONTROLLER //Depends on the bonus question
	{
		printf(" Engine Temp Controller is %s\n", System.EngineTempController);
		printf(" Engine Temperature is: %d C\n\n\n", System.Etemp);
	}
#else
	{
		puts("\n\n");
		// Do nothing
	}
#endif
}

// Just Giving Initial values for system status
void InitializingStatus(void)
{
	strcpy(System.Engine, "ON"); //Engine is ON
	strcpy(System.EngineTempController, "OFF"); // Engine Controller is OFF
	strcpy(System.AC, "OFF"); // AC is OFF
	System.Rtemp = 29; //Setting room temperature to 29
	System.Etemp = 112; // Setting Engine temperature to 112

	// Giving values to System status depending on the requirements
	if (System.Rtemp < 10 || System.Rtemp > 30)
	{
		strcpy(System.AC, "ON");
		//			Setting Room temperature to 20
		System.Rtemp = 20;
	}
	else
	{
		strcpy(System.AC, "OFF");
	}

#if WITH_ENGINE_TEMP_CONTROLLER // If zero in preprocessor state will not add this line of codes so that the compiler will not see that
	{


		if (System.Etemp > 150 || System.Etemp < 100)
		{
			strcpy(System.EngineTempController, "ON");
			//	setting Engine temperature back to 125
			System.Etemp = 125;
		}
		else
		{
			strcpy(System.EngineTempController, "OFF");
		}
	}
#endif
}

void FirstPageDisplay()
{
	printf(" 	Welcome 	\n");
	printf(" a. Turn on the vehicle engine\n");
	printf(" b. Turn off the vehicle engine\n");
	printf(" c. Quit the system\n\n");
	fflush(stdout);
	scanf(" %c", &welcomeoptions);  //Getting the first list option from the user 1- turn engine on 2- Quit from the system
	return;
}

ENUM Traffic()
{
	puts(" Enter the required color: ");
	fflush(stdout);
	scanf(" %c", &RandomOptions);

	switch (RandomOptions)
	{
	case('G'): System.Vspeed = 100;
		break;
	case('O'): System.Vspeed = 30;
		break;
	case('R'): System.Vspeed = 0;
		break;
	default:puts("Enter a correct option\n"); return incorrect;
	}
	return correct;
}

void RoomTemp()
{
	printf(" Enter the room temperature: \n");
	fflush(stdout);
	scanf(" %d", &System.Rtemp);

	if (System.Rtemp < 10 || System.Rtemp > 30)
	{
		strcpy(System.AC, "ON");
		//			Setting Room temperature to 20
		System.Rtemp = 20;
	}
	else
	{
		strcpy(System.AC, "OFF");
	}
}

#if WITH_ENGINE_TEMP_CONTROLLER // will compile depending on the bonus requirement

void EngineTemp()
{
	puts(" Enter the Engine Temperature: ");
	fflush(stdout);
	scanf(" %d", &System.Etemp);
	if (System.Etemp > 150 || System.Etemp < 100)
	{
		strcpy(System.EngineTempController, "ON");
		//	setting Enine temperature back to 125
		System.Etemp = 125;
		return;
	}
	else
	{
		strcpy(System.EngineTempController, "OFF");
		return;
	}

}
#endif


ENUM OptionA() //TURNING on the vehicle list
{
	strcpy(System.Engine, "ON"); // Turning the engine ON
	puts(" a. Turn off the engine \n b. Set the traffic light color \n c. Set the room temperature");
#if WITH_ENGINE_TEMP_CONTROLLER // Bonus requirement
	{
		puts(" d. Set the engine temperature\n");
	}
#endif
	fflush(stdout);
	scanf(" %c", &welcomeoptions); // getting input from the user for the second page which includes turn off the engine ...

	if (welcomeoptions == 'a')
	{
		printf(" Turning off the vehicle engine\n");
		strcpy(System.Engine, "OFF");
		return correct;
	}
	else if (welcomeoptions == 'b') // for Traffic requirement
	{
		while (Traffic() == incorrect)
		{
		}
	}
	else if (welcomeoptions == 'c') // Entering the room the temperature
	{
		RoomTemp();
	}
	else if (welcomeoptions == 'd' && WITH_ENGINE_TEMP_CONTROLLER)
	{
#if WITH_ENGINE_TEMP_CONTROLLER // will compile depending on the bonus requirement
		{
			EngineTemp();
		}
#endif
	}
	else
	{
		printf("Please choose a correct option\n");
		fflush(stdout);
		return incorrect;
	}

	// Depending on the vehicle speed
	if (System.Vspeed == 30)
	{
		strcpy(System.AC, "ON");
		System.Rtemp = (System.Rtemp) * 1.25 + 1;

		strcpy(System.EngineTempController, "ON");
		System.Etemp = (System.Etemp) * 1.25 + 1;
	}

	DisplayStatus();
	return incorrect;
}


int main(void)
{
	while (Exit == 0)
	{
		FirstPageDisplay();

		switch (welcomeoptions)
		{
		case('a'): //First option vehicle ON
			puts(" Turning Vehicle's engine on\n");
			InitializingStatus(); // Just giving Initial values
			while (OptionA() == incorrect) // will call the loop back if it got incorrect input from the user
			{
				//Do nothing
			}
			break;
		case('b'):printf(" Turninng off the vehicle's engine \n"); break; //Turning of the vehicle
		case('c'):printf(" Quitting from the system\n"); Exit = 1; break;
		default:  break;
		}
	}


	return 0;
}
