/*----- PROTECTED REGION ID(PSDTex.cpp) ENABLED START -----*/
//=============================================================================
//
// file :        PSDTex.cpp
//
// description : C++ source for the PSDTex class and its commands.
//               The class is derived from Device. It represents the
//               CORBA servant object which will be accessed from the
//               network. All commands which can be executed on the
//               PSDTex are implemented in this file.
//
// project :     
//
// This file is part of Tango device class.
// 
// Tango is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// Tango is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with Tango.  If not, see <http://www.gnu.org/licenses/>.
// 
//
//
//=============================================================================
//                This file is generated by POGO
//        (Program Obviously used to Generate tango Object)
//=============================================================================


#include <PSDTex.h>
#include <PSDTexClass.h>

/*----- PROTECTED REGION END -----*/	//	PSDTex.cpp

/**
 *  PSDTex class description:
 *    
 */

//================================================================
//  The following table gives the correspondence
//  between command and method names.
//
//  Command name  |  Method name
//================================================================
//  State         |  Inherited (no method)
//  Status        |  Inherited (no method)
//  Start         |  start
//  Stop          |  stop
//  Clear         |  clear
//================================================================

//================================================================
//  Attributes managed is:
//================================================================
//  image  |  Tango::DevDouble	Image  ( max = 256 x 256)
//================================================================

namespace PSDTex_ns
{
/*----- PROTECTED REGION ID(PSDTex::namespace_starting) ENABLED START -----*/

//	static initializations

/*----- PROTECTED REGION END -----*/	//	PSDTex::namespace_starting

//--------------------------------------------------------
/**
 *	Method      : PSDTex::PSDTex()
 *	Description : Constructors for a Tango device
 *                implementing the classPSDTex
 */
//--------------------------------------------------------
PSDTex::PSDTex(Tango::DeviceClass *cl, string &s)
 : TANGO_BASE_CLASS(cl, s.c_str())
{
	/*----- PROTECTED REGION ID(PSDTex::constructor_1) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::constructor_1
}
//--------------------------------------------------------
PSDTex::PSDTex(Tango::DeviceClass *cl, const char *s)
 : TANGO_BASE_CLASS(cl, s)
{
	/*----- PROTECTED REGION ID(PSDTex::constructor_2) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::constructor_2
}
//--------------------------------------------------------
PSDTex::PSDTex(Tango::DeviceClass *cl, const char *s, const char *d)
 : TANGO_BASE_CLASS(cl, s, d)
{
	/*----- PROTECTED REGION ID(PSDTex::constructor_3) ENABLED START -----*/
	init_device();
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::constructor_3
}

//--------------------------------------------------------
/**
 *	Method      : PSDTex::delete_device()
 *	Description : will be called at device destruction or at init command
 */
//--------------------------------------------------------
void PSDTex::delete_device()
{
	DEBUG_STREAM << "PSDTex::delete_device() " << device_name << endl;
	/*----- PROTECTED REGION ID(PSDTex::delete_device) ENABLED START -----*/
	
	//	Delete device allocated objects
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::delete_device
	delete[] attr_image_read;
}

//--------------------------------------------------------
/**
 *	Method      : PSDTex::init_device()
 *	Description : will be called at device initialization.
 */
//--------------------------------------------------------
void PSDTex::init_device()
{
	DEBUG_STREAM << "PSDTex::init_device() create device " << device_name << endl;
	/*----- PROTECTED REGION ID(PSDTex::init_device_before) ENABLED START -----*/
	
	//	Initialization before get_device_property() call
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::init_device_before
	

	//	Get the device properties from database
	get_device_property();
	
	attr_image_read = new Tango::DevDouble[256*256];
	/*----- PROTECTED REGION ID(PSDTex::init_device) ENABLED START -----*/
	
    clearImage();
    if(pd!=nullptr) delete pd;
    pd = new PLX9030Detector::plx9030Detector(devicefile_path);

	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::init_device
}

//--------------------------------------------------------
/**
 *	Method      : PSDTex::get_device_property()
 *	Description : Read database to initialize property data members.
 */
//--------------------------------------------------------
void PSDTex::get_device_property()
{
	/*----- PROTECTED REGION ID(PSDTex::get_device_property_before) ENABLED START -----*/
	
	//	Initialize property data members
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::get_device_property_before


	//	Read device properties from database.
	Tango::DbData	dev_prop;
	dev_prop.push_back(Tango::DbDatum("devicefile_path"));
	dev_prop.push_back(Tango::DbDatum("manual_ceoff"));
	dev_prop.push_back(Tango::DbDatum("coeff_x"));
	dev_prop.push_back(Tango::DbDatum("coeff_y"));

	//	is there at least one property to be read ?
	if (dev_prop.size()>0)
	{
		//	Call database and extract values
		if (Tango::Util::instance()->_UseDb==true)
			get_db_device()->get_property(dev_prop);
	
		//	get instance on PSDTexClass to get class property
		Tango::DbDatum	def_prop, cl_prop;
		PSDTexClass	*ds_class =
			(static_cast<PSDTexClass *>(get_device_class()));
		int	i = -1;

		//	Try to initialize devicefile_path from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  devicefile_path;
		else {
			//	Try to initialize devicefile_path from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  devicefile_path;
		}
		//	And try to extract devicefile_path value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  devicefile_path;

		//	Try to initialize manual_ceoff from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  manual_ceoff;
		else {
			//	Try to initialize manual_ceoff from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  manual_ceoff;
		}
		//	And try to extract manual_ceoff value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  manual_ceoff;

		//	Try to initialize coeff_x from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  coeff_x;
		else {
			//	Try to initialize coeff_x from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  coeff_x;
		}
		//	And try to extract coeff_x value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  coeff_x;

		//	Try to initialize coeff_y from class property
		cl_prop = ds_class->get_class_property(dev_prop[++i].name);
		if (cl_prop.is_empty()==false)	cl_prop  >>  coeff_y;
		else {
			//	Try to initialize coeff_y from default device value
			def_prop = ds_class->get_default_device_property(dev_prop[i].name);
			if (def_prop.is_empty()==false)	def_prop  >>  coeff_y;
		}
		//	And try to extract coeff_y value from database
		if (dev_prop[i].is_empty()==false)	dev_prop[i]  >>  coeff_y;

	}

	/*----- PROTECTED REGION ID(PSDTex::get_device_property_after) ENABLED START -----*/
	
	//	Check device property data members init
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::get_device_property_after
}

//--------------------------------------------------------
/**
 *	Method      : PSDTex::always_executed_hook()
 *	Description : method always executed before any command is executed
 */
//--------------------------------------------------------
void PSDTex::always_executed_hook()
{
	DEBUG_STREAM << "PSDTex::always_executed_hook()  " << device_name << endl;
	/*----- PROTECTED REGION ID(PSDTex::always_executed_hook) ENABLED START -----*/
	
	//	code always executed before all requests
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::always_executed_hook
}

//--------------------------------------------------------
/**
 *	Method      : PSDTex::read_attr_hardware()
 *	Description : Hardware acquisition for attributes
 */
//--------------------------------------------------------
void PSDTex::read_attr_hardware(TANGO_UNUSED(vector<long> &attr_list))
{
	DEBUG_STREAM << "PSDTex::read_attr_hardware(vector<long> &attr_list) entering... " << endl;
	/*----- PROTECTED REGION ID(PSDTex::read_attr_hardware) ENABLED START -----*/
	
	//	Add your own code
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::read_attr_hardware
}

//--------------------------------------------------------
/**
 *	Read attribute image related method
 *	Description: 
 *
 *	Data type:	Tango::DevDouble
 *	Attr type:	Image max = 256 x 256
 */
//--------------------------------------------------------
void PSDTex::read_image(Tango::Attribute &attr)
{
	DEBUG_STREAM << "PSDTex::read_image(Tango::Attribute &attr) entering... " << endl;
	/*----- PROTECTED REGION ID(PSDTex::read_image) ENABLED START -----*/

    const int size_x = 256;
    const int size_y = 256;

    int sum_x {0}, sum_y{0}, ix{0},iy{0};
    double c_x{1.0},c_y{1.0};

    PLX9030Detector::four_value data4;
    do{
        data4 = pd->read4Value();
        if(!data4.correct) continue;
        sum_x = data4.x1+data4.x2;
        sum_y = data4.y1+data4.y2;

        if(manual_ceoff){
            c_x = coeff_x;
            c_y = coeff_y;
        }else{
            c_x = (double)size_x/(double)sum_x;
            c_y = (double)size_y/(double)sum_y;
        }


        ix = data4.x2-data4.x1;
        iy = data4.y2-data4.y1;

        ix = (int)(ix*c_x+0.5);
        iy = (int)(iy*c_y+0.5);


        //ix = (int)size_x*data4.x1/(data4.x1+data4.x2)-size_x/2;
        //iy = (int)size_y*data4.y1/(data4.y1+data4.y2)-size_y/2;

        //std::cout << ix << " " << iy << "\n";

        //emit setCell(ix,iy,1);
        setImageCell(ix,iy,1.0);
    }while(data4.correct);

	attr.set_value(attr_image_read, 256, 256);
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::read_image
}

//--------------------------------------------------------
/**
 *	Method      : PSDTex::add_dynamic_attributes()
 *	Description : Create the dynamic attributes if any
 *                for specified device.
 */
//--------------------------------------------------------
void PSDTex::add_dynamic_attributes()
{
	/*----- PROTECTED REGION ID(PSDTex::add_dynamic_attributes) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic attributes if any
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::add_dynamic_attributes
}

//--------------------------------------------------------
/**
 *	Command Start related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void PSDTex::start()
{
	DEBUG_STREAM << "PSDTex::Start()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PSDTex::start) ENABLED START -----*/

    pd->init();
    pd->start();
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::start
}
//--------------------------------------------------------
/**
 *	Command Stop related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void PSDTex::stop()
{
	DEBUG_STREAM << "PSDTex::Stop()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PSDTex::stop) ENABLED START -----*/
	
    pd->stop();
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::stop
}
//--------------------------------------------------------
/**
 *	Command Clear related method
 *	Description: 
 *
 */
//--------------------------------------------------------
void PSDTex::clear()
{
	DEBUG_STREAM << "PSDTex::Clear()  - " << device_name << endl;
	/*----- PROTECTED REGION ID(PSDTex::clear) ENABLED START -----*/

    clearImage();
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::clear
}
//--------------------------------------------------------
/**
 *	Method      : PSDTex::add_dynamic_commands()
 *	Description : Create the dynamic commands if any
 *                for specified device.
 */
//--------------------------------------------------------
void PSDTex::add_dynamic_commands()
{
	/*----- PROTECTED REGION ID(PSDTex::add_dynamic_commands) ENABLED START -----*/
	
	//	Add your own code to create and add dynamic commands if any
	
	/*----- PROTECTED REGION END -----*/	//	PSDTex::add_dynamic_commands
}

/*----- PROTECTED REGION ID(PSDTex::namespace_ending) ENABLED START -----*/

// -128 < x < 128
void PSDTex::setImageCell(int x, int y, Tango::DevDouble value){
    int size_x = 256;
    int size_y = 256;

    if(x>(size_x/2) || x<(-size_x/2)) return;
    if(y>(size_y/2) || y<(-size_y/2)) return;

    int index = x + size_x/2 +  (y+size_y/2)*size_x;
    attr_image_read[index] += value;
}

void PSDTex::clearImage(){
    int size_x = 256;
    int size_y = 256;

    for(int i=0;i<size_x*size_y;i++) attr_image_read[i] = (Tango::DevDouble)0.0;
}

/*----- PROTECTED REGION END -----*/	//	PSDTex::namespace_ending
} //	namespace