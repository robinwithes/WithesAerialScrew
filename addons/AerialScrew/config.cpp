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
    class Withes_Screw: Heli_Light_01_base_F {
        armor = 200;
        altFullForce = 900; /// in what height do the engines still have full thrust
        altNoForce = 1800; /// thrust of the engines interpolates to zero between altFullForce and altNoForce
        maxSpeed = 200; /// what is the maximum speed of the vehicle
        maxFordingDepth = 1; /// how deep could the vehicle be in water without getting some damage
        hasDriver = true;	// default
        hasGunner = false;	// default
        hasCommander = false;	// default
        mainBladeRadius = 3; /// describes the radius of main rotor - used for collision detection	
        //multiplier of body friction
        bodyFrictionCoef = 0.1;
        //multiplier of dive force
        cyclicForwardForceCoef = 1.0;
        //multiplier of back rotor force
        backRotorForceCoef = 1.0;
        transportSoldier = 0;
        startDuration = 8;
        cargoCanEject = 1; 
        driverCanEject = 1; 
        mainRotorSpeed = 0.4;
        precisegetinout = 0;
        helmetMountedDisplay = 0;
        getInRadius = 15;
        driverAction = "Withes_Screw_Pilot";
		driverInAction = "Withes_Screw_Pilot";
        maximumLoad = 1000;
        scope = 2;
        author = "Robin Withes";
        _generalMacro = "Withes_Screw";
        displayname = "Aerial Screw";
        model = "\AerialScrew\model\Screw.p3d";
        class Library {
            libTextDesc = "A famous contraption made by Leonardo Da Vinci!";
        };
        class MFD{};
		class TransportBackpacks{};
		class TransportItems{};
        class TransportWeapons{};
        class Turrets{};
        class ViewPilot: ViewPilot
		{
			initFov=1.4;
			minFov=0.60000002;
			maxFov=1;
            initAngleX = 0;
            minAngleX = -30;
            maxAngleX = 30;
            initAngleY = 180;
            minAngleY = 0;
            maxAngleY = 360;
		};
    };
};