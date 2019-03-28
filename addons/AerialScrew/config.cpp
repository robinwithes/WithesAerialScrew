class CfgPatches {
    class Withes_Screw_Patch {
        units[] = {
            "Withes_Screw"
        };
        weapons[] = {};
        requiredVersion = 0.100000;
        requiredAddons[] = {
            "A3_Air_F"
        };
    };
};

class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		Withes_Screw_Pilot = "Withes_Screw_Pilot";
	};
	class Actions
	{
		class RifleBaseLowStandActions;
		class para_actions: RifleBaseLowStandActions
		{
			Die = "KIA_Para_Pilot";
		};
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;
		class AmovPercMstpSnonWnonDnon;
		class PreciseCrew: Crew
		{
			head = "headNo";
		};
		class Withes_Screw_Pilot: Crew
		{
			file = "\AerialScrew\anim\Withes_Screw_Pilot.rtm";
		};
	};
};

class CfgVehicles {
    class Heli_Light_01_base_F;
    class ViewPilot;
    class MainTurret;
    class Turrets;

    class Withes_Screw: Heli_Light_01_base_F {
        armor = 10;
        altFullForce = 2000; /// in what height do the engines still have full thrust
        altNoForce = 7000; /// thrust of the engines interpolates to zero between altFullForce and altNoForce
        maxSpeed = 30; /// what is the maximum speed of the vehicle
        maxFordingDepth = 1; /// how deep could the vehicle be in water without getting some damage
        hasDriver = true;	// default
        hasGunner = false;	// default
        hasCommander = false;	// default
        mainBladeRadius = 1; /// describes the radius of main rotor - used for collision detection	
        //multiplier of body friction
        bodyFrictionCoef = 0.1;
        //multiplier of dive force
        cyclicForwardForceCoef = 1.0;
        //multiplier of back rotor force
        backRotorForceCoef = 1.0;
        startDuration = 14;
        cargoCanEject = 1;
        driverCanEject = 1;
        mainRotorSpeed = 0.43;
        precisegetinout = 0;
        helmetMountedDisplay = 0;
        getInRadius = 17;
        driverAction = "Withes_Screw_Pilot";
		driverInAction = "Withes_Screw_Pilot";
        maximumLoad = 1000;
        scope = 2;
        transportSoldier = 0;
        author = "Robin Withes";
        _generalMacro = "Withes_Screw";
        displayname = "Aerial Screw";
        model = "\AerialScrew\model\Screw.p3d";
        memoryPointsGetInCargo = "pos cargo";		/// on what memory points should the cargo get in the heli
		memoryPointsGetInCargoDir = "pos cargo dir";/// what is the direction of the cargo facing during get in animation (and opposite for get out)
        memoryPointsGetInDriver = "pos cargo";		/// on what memory points should the cargo get in the heli
		memoryPointsGetInDriverDir = "pos cargo dir";/// what is the direction of the cargo facing during get in animation (and opposite for get out)
        cargoIsCoDriver[] = {0, 0}; 				/// the cargo don't utilize some special memory points to get in
        hideWeaponsCargo = 1;						/// this makes the poses easier and adds some performance gain because the proxies don't need to be drawn
        cargoProxyIndexes[] = {1,2,3};		/// what indexes does regular cargo sit on
        class Library {
            libTextDesc = "A famous contraption made by Leonardo Da Vinci!";
        };
        class MFD{};
		class TransportBackpacks{};
		class TransportItems{};
        class TransportWeapons{};
        class ViewPilot: ViewPilot
		{
			initFov=1.4;
			minFov=0.60000002;
			maxFov=1;
            initAngleX = 0;
            minAngleX = -40;
            maxAngleX = 40;
            initAngleY = 0;
            minAngleY = -100;
            maxAngleY = 100;
		};

        class Turrets: Turrets										/// just a copilot seat as a turret to enable taking the controls
		{
			class screw_seat_1: MainTurret 						/// position for Firing from Vehicles
			{
                proxyType = "CPGunner";
				gunnerAction 				= "Withes_Screw_Pilot";
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo dir";	/// direction of get in action
				gunnerName 					= "Slave 1";	/// name of the position in the Action menu
				proxyIndex 					= 1;					/// what cargo proxy is used according to index in the model
				maxElev 					= 15;					/// what is the highest possible elevation of the turret
				minElev 					= -25;					/// what is the lowest possible elevation of the turret
				maxTurn 					= 45;					/// what is the left-most possible turn of the turret
				minTurn 					= -15;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 0;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 1;					/// seatbelts included
                canEject = 1;
			};
            class screw_seat_2: screw_seat_1
            {
                gunnerName 					= "Slave 2";	/// name of the position in the Action menu
                proxyIndex 					= 2;					/// what cargo proxy is used according to index in the model
            };
            class screw_seat_3: screw_seat_1
            {
                gunnerName 					= "Slave 3";	/// name of the position in the Action menu
                proxyIndex 					= 3;					/// what cargo proxy is used according to index in the model
            };
		};
    };
};