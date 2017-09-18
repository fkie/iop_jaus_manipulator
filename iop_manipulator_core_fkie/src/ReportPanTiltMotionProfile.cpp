#include "iop_manipulator_core_fkie/ReportPanTiltMotionProfile.h"

namespace iop_manipulator_core_fkie
{

void ReportPanTiltMotionProfile::AppHeader::HeaderRec::setParent(AppHeader* parent)
{
	m_parent = parent;
}

void ReportPanTiltMotionProfile::AppHeader::HeaderRec::setParentPresenceVector()
{
	if(m_parent != NULL )
	{
		m_parent->setParentPresenceVector();
	}
}

jUnsignedShortInteger ReportPanTiltMotionProfile::AppHeader::HeaderRec::getMessageID()
{
	return m_MessageID;
}

int ReportPanTiltMotionProfile::AppHeader::HeaderRec::setMessageID(jUnsignedShortInteger value)
{
	m_MessageID = value;
	setParentPresenceVector();
	return 0;
}

/**
 * Returns the size of memory the used data members of the class occupies.
 * This is not necessarily the same size of memory the class actually occupies.
 * Eg. A union of an int and a double may occupy 8 bytes. However, if the data
 *     stored is an int, this function will return a size of 4 bytes.
 *
 * @return
 */
const unsigned int ReportPanTiltMotionProfile::AppHeader::HeaderRec::getSize()
{
	unsigned int size = 0;

	size += sizeof(jUnsignedShortInteger);

	return size;
}

void ReportPanTiltMotionProfile::AppHeader::HeaderRec::encode(unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	jUnsignedShortInteger m_MessageIDTemp;

	m_MessageIDTemp = JSIDL_v_1_0::correctEndianness(m_MessageID);
	memcpy(bytes + pos, &m_MessageIDTemp, sizeof(jUnsignedShortInteger));
	pos += sizeof(jUnsignedShortInteger);
}

void ReportPanTiltMotionProfile::AppHeader::HeaderRec::decode(const unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	jUnsignedShortInteger m_MessageIDTemp;

	memcpy(&m_MessageIDTemp, bytes + pos, sizeof(jUnsignedShortInteger));
	m_MessageID = JSIDL_v_1_0::correctEndianness(m_MessageIDTemp);
	pos += sizeof(jUnsignedShortInteger);
}

ReportPanTiltMotionProfile::AppHeader::HeaderRec &ReportPanTiltMotionProfile::AppHeader::HeaderRec::operator=(const HeaderRec &value)
{
	m_MessageID = value.m_MessageID;

	return *this;
}

bool ReportPanTiltMotionProfile::AppHeader::HeaderRec::operator==(const HeaderRec &value) const
{
	if (m_MessageID != value.m_MessageID)
	{
		return false;
	}

	return true;
}

bool ReportPanTiltMotionProfile::AppHeader::HeaderRec::operator!=(const HeaderRec &value) const
{
	return !((*this) == value);
}

ReportPanTiltMotionProfile::AppHeader::HeaderRec::HeaderRec()
{
	m_parent = NULL;
	m_MessageID = 0x4627;
}

ReportPanTiltMotionProfile::AppHeader::HeaderRec::HeaderRec(const HeaderRec &value)
{
	/// Initiliaze the protected variables
	m_parent = NULL;
	m_MessageID = 0x4627;

	/// Copy the values
	m_MessageID = value.m_MessageID;
}

ReportPanTiltMotionProfile::AppHeader::HeaderRec::~HeaderRec()
{
}

ReportPanTiltMotionProfile::AppHeader::HeaderRec* const ReportPanTiltMotionProfile::AppHeader::getHeaderRec()
{
	return &m_HeaderRec;
}

int ReportPanTiltMotionProfile::AppHeader::setHeaderRec(const HeaderRec &value)
{
	m_HeaderRec = value;
	setParentPresenceVector();
	return 0;
}

void ReportPanTiltMotionProfile::AppHeader::setParentPresenceVector()
{
	// Nothing needed here, placeholder function
}

/**
 * Returns the size of memory the used data members of the class occupies.
 * This is not necessarily the same size of memory the class actually occupies.
 * Eg. A union of an int and a double may occupy 8 bytes. However, if the data
 *     stored is an int, this function will return a size of 4 bytes.
 *
 * @return
 */
const unsigned int ReportPanTiltMotionProfile::AppHeader::getSize()
{
	unsigned int size = 0;

	size += m_HeaderRec.getSize();

	return size;
}

void ReportPanTiltMotionProfile::AppHeader::encode(unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	m_HeaderRec.encode(bytes + pos);
	pos += m_HeaderRec.getSize();
}

void ReportPanTiltMotionProfile::AppHeader::decode(const unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	m_HeaderRec.decode(bytes + pos);
	pos += m_HeaderRec.getSize();
}

ReportPanTiltMotionProfile::AppHeader &ReportPanTiltMotionProfile::AppHeader::operator=(const AppHeader &value)
{
	m_HeaderRec = value.m_HeaderRec;
	m_HeaderRec.setParent(this);

	return *this;
}

bool ReportPanTiltMotionProfile::AppHeader::operator==(const AppHeader &value) const
{
	if (m_HeaderRec != value.m_HeaderRec)
	{
		return false;
	}
	return true;
}

bool ReportPanTiltMotionProfile::AppHeader::operator!=(const AppHeader &value) const
{
	return !((*this) == value);
}

ReportPanTiltMotionProfile::AppHeader::AppHeader()
{
	m_HeaderRec.setParent(this);
	/// No Initialization of m_HeaderRec necessary.
}

ReportPanTiltMotionProfile::AppHeader::AppHeader(const AppHeader &value)
{
	/// Initiliaze the protected variables
	m_HeaderRec.setParent(this);
	/// No Initialization of m_HeaderRec necessary.

	/// Copy the values
	m_HeaderRec = value.m_HeaderRec;
	m_HeaderRec.setParent(this);
}

ReportPanTiltMotionProfile::AppHeader::~AppHeader()
{
}

ReportPanTiltMotionProfile::AppHeader* const ReportPanTiltMotionProfile::getAppHeader()
{
	return &m_AppHeader;
}

int ReportPanTiltMotionProfile::setAppHeader(const AppHeader &value)
{
	m_AppHeader = value;
	return 0;
}

void ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::setParent(Body* parent)
{
	m_parent = parent;
}

void ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::setParentPresenceVector()
{
	if(m_parent != NULL )
	{
		m_parent->setParentPresenceVector();
	}
}

double ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::getJoint1MaxSpeed()
{
	double value;

	double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
	double bias = 0.0;

	value = m_Joint1MaxSpeed * scaleFactor + bias;

	return value;
}

int ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::setJoint1MaxSpeed(double value)
{
	if ((value >= 0.0) && (value <= 10*3.14159265358979323846))
	{
		double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
		double bias = 0.0;

		m_Joint1MaxSpeed= (jUnsignedInteger)((value - bias) / scaleFactor);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

double ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::getJoint1MaxAccelerationRate()
{
	double value;

	double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
	double bias = 0.0;

	value = m_Joint1MaxAccelerationRate * scaleFactor + bias;

	return value;
}

int ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::setJoint1MaxAccelerationRate(double value)
{
	if ((value >= 0.0) && (value <= 10*3.14159265358979323846))
	{
		double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
		double bias = 0.0;

		m_Joint1MaxAccelerationRate= (jUnsignedInteger)((value - bias) / scaleFactor);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

double ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::getJoint1MaxDecelerationRate()
{
	double value;

	double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
	double bias = 0.0;

	value = m_Joint1MaxDecelerationRate * scaleFactor + bias;

	return value;
}

int ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::setJoint1MaxDecelerationRate(double value)
{
	if ((value >= 0.0) && (value <= 10*3.14159265358979323846))
	{
		double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
		double bias = 0.0;

		m_Joint1MaxDecelerationRate= (jUnsignedInteger)((value - bias) / scaleFactor);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

double ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::getJoint2MaxSpeed()
{
	double value;

	double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
	double bias = 0.0;

	value = m_Joint2MaxSpeed * scaleFactor + bias;

	return value;
}

int ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::setJoint2MaxSpeed(double value)
{
	if ((value >= 0.0) && (value <= 10*3.14159265358979323846))
	{
		double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
		double bias = 0.0;

		m_Joint2MaxSpeed= (jUnsignedInteger)((value - bias) / scaleFactor);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

double ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::getJoint2MaxAccelerationRate()
{
	double value;

	double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
	double bias = 0.0;

	value = m_Joint2MaxAccelerationRate * scaleFactor + bias;

	return value;
}

int ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::setJoint2MaxAccelerationRate(double value)
{
	if ((value >= 0.0) && (value <= 10*3.14159265358979323846))
	{
		double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
		double bias = 0.0;

		m_Joint2MaxAccelerationRate= (jUnsignedInteger)((value - bias) / scaleFactor);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

double ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::getJoint2MaxDecelerationRate()
{
	double value;

	double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
	double bias = 0.0;

	value = m_Joint2MaxDecelerationRate * scaleFactor + bias;

	return value;
}

int ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::setJoint2MaxDecelerationRate(double value)
{
	if ((value >= 0.0) && (value <= 10*3.14159265358979323846))
	{
		double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
		double bias = 0.0;

		m_Joint2MaxDecelerationRate= (jUnsignedInteger)((value - bias) / scaleFactor);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

/**
 * Returns the size of memory the used data members of the class occupies.
 * This is not necessarily the same size of memory the class actually occupies.
 * Eg. A union of an int and a double may occupy 8 bytes. However, if the data
 *     stored is an int, this function will return a size of 4 bytes.
 *
 * @return
 */
const unsigned int ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::getSize()
{
	unsigned int size = 0;

	size += sizeof(jUnsignedInteger);
	size += sizeof(jUnsignedInteger);
	size += sizeof(jUnsignedInteger);
	size += sizeof(jUnsignedInteger);
	size += sizeof(jUnsignedInteger);
	size += sizeof(jUnsignedInteger);

	return size;
}

void ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::encode(unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	jUnsignedInteger m_Joint1MaxSpeedTemp;

	m_Joint1MaxSpeedTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxSpeed);
	memcpy(bytes + pos, &m_Joint1MaxSpeedTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint1MaxAccelerationRateTemp;

	m_Joint1MaxAccelerationRateTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxAccelerationRate);
	memcpy(bytes + pos, &m_Joint1MaxAccelerationRateTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint1MaxDecelerationRateTemp;

	m_Joint1MaxDecelerationRateTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxDecelerationRate);
	memcpy(bytes + pos, &m_Joint1MaxDecelerationRateTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MaxSpeedTemp;

	m_Joint2MaxSpeedTemp = JSIDL_v_1_0::correctEndianness(m_Joint2MaxSpeed);
	memcpy(bytes + pos, &m_Joint2MaxSpeedTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MaxAccelerationRateTemp;

	m_Joint2MaxAccelerationRateTemp = JSIDL_v_1_0::correctEndianness(m_Joint2MaxAccelerationRate);
	memcpy(bytes + pos, &m_Joint2MaxAccelerationRateTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MaxDecelerationRateTemp;

	m_Joint2MaxDecelerationRateTemp = JSIDL_v_1_0::correctEndianness(m_Joint2MaxDecelerationRate);
	memcpy(bytes + pos, &m_Joint2MaxDecelerationRateTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
}

void ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::decode(const unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	jUnsignedInteger m_Joint1MaxSpeedTemp;

	memcpy(&m_Joint1MaxSpeedTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint1MaxSpeed = JSIDL_v_1_0::correctEndianness(m_Joint1MaxSpeedTemp);
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint1MaxAccelerationRateTemp;

	memcpy(&m_Joint1MaxAccelerationRateTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint1MaxAccelerationRate = JSIDL_v_1_0::correctEndianness(m_Joint1MaxAccelerationRateTemp);
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint1MaxDecelerationRateTemp;

	memcpy(&m_Joint1MaxDecelerationRateTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint1MaxDecelerationRate = JSIDL_v_1_0::correctEndianness(m_Joint1MaxDecelerationRateTemp);
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MaxSpeedTemp;

	memcpy(&m_Joint2MaxSpeedTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint2MaxSpeed = JSIDL_v_1_0::correctEndianness(m_Joint2MaxSpeedTemp);
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MaxAccelerationRateTemp;

	memcpy(&m_Joint2MaxAccelerationRateTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint2MaxAccelerationRate = JSIDL_v_1_0::correctEndianness(m_Joint2MaxAccelerationRateTemp);
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MaxDecelerationRateTemp;

	memcpy(&m_Joint2MaxDecelerationRateTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint2MaxDecelerationRate = JSIDL_v_1_0::correctEndianness(m_Joint2MaxDecelerationRateTemp);
	pos += sizeof(jUnsignedInteger);
}

ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec &ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::operator=(const PanTiltMotionProfileRec &value)
{
	m_Joint1MaxSpeed = value.m_Joint1MaxSpeed;
	m_Joint1MaxAccelerationRate = value.m_Joint1MaxAccelerationRate;
	m_Joint1MaxDecelerationRate = value.m_Joint1MaxDecelerationRate;
	m_Joint2MaxSpeed = value.m_Joint2MaxSpeed;
	m_Joint2MaxAccelerationRate = value.m_Joint2MaxAccelerationRate;
	m_Joint2MaxDecelerationRate = value.m_Joint2MaxDecelerationRate;

	return *this;
}

bool ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::operator==(const PanTiltMotionProfileRec &value) const
{
	if (m_Joint1MaxSpeed != value.m_Joint1MaxSpeed)
	{
		return false;
	}
	if (m_Joint1MaxAccelerationRate != value.m_Joint1MaxAccelerationRate)
	{
		return false;
	}
	if (m_Joint1MaxDecelerationRate != value.m_Joint1MaxDecelerationRate)
	{
		return false;
	}
	if (m_Joint2MaxSpeed != value.m_Joint2MaxSpeed)
	{
		return false;
	}
	if (m_Joint2MaxAccelerationRate != value.m_Joint2MaxAccelerationRate)
	{
		return false;
	}
	if (m_Joint2MaxDecelerationRate != value.m_Joint2MaxDecelerationRate)
	{
		return false;
	}

	return true;
}

bool ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::operator!=(const PanTiltMotionProfileRec &value) const
{
	return !((*this) == value);
}

ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::PanTiltMotionProfileRec()
{
	m_parent = NULL;
	m_Joint1MaxSpeed = 0;
	m_Joint1MaxAccelerationRate = 0;
	m_Joint1MaxDecelerationRate = 0;
	m_Joint2MaxSpeed = 0;
	m_Joint2MaxAccelerationRate = 0;
	m_Joint2MaxDecelerationRate = 0;
}

ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::PanTiltMotionProfileRec(const PanTiltMotionProfileRec &value)
{
	/// Initiliaze the protected variables
	m_parent = NULL;
	m_Joint1MaxSpeed = 0;
	m_Joint1MaxAccelerationRate = 0;
	m_Joint1MaxDecelerationRate = 0;
	m_Joint2MaxSpeed = 0;
	m_Joint2MaxAccelerationRate = 0;
	m_Joint2MaxDecelerationRate = 0;

	/// Copy the values
	m_Joint1MaxSpeed = value.m_Joint1MaxSpeed;
	m_Joint1MaxAccelerationRate = value.m_Joint1MaxAccelerationRate;
	m_Joint1MaxDecelerationRate = value.m_Joint1MaxDecelerationRate;
	m_Joint2MaxSpeed = value.m_Joint2MaxSpeed;
	m_Joint2MaxAccelerationRate = value.m_Joint2MaxAccelerationRate;
	m_Joint2MaxDecelerationRate = value.m_Joint2MaxDecelerationRate;
}

ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec::~PanTiltMotionProfileRec()
{
}

ReportPanTiltMotionProfile::Body::PanTiltMotionProfileRec* const ReportPanTiltMotionProfile::Body::getPanTiltMotionProfileRec()
{
	return &m_PanTiltMotionProfileRec;
}

int ReportPanTiltMotionProfile::Body::setPanTiltMotionProfileRec(const PanTiltMotionProfileRec &value)
{
	m_PanTiltMotionProfileRec = value;
	setParentPresenceVector();
	return 0;
}

void ReportPanTiltMotionProfile::Body::setParentPresenceVector()
{
	// Nothing needed here, placeholder function
}

/**
 * Returns the size of memory the used data members of the class occupies.
 * This is not necessarily the same size of memory the class actually occupies.
 * Eg. A union of an int and a double may occupy 8 bytes. However, if the data
 *     stored is an int, this function will return a size of 4 bytes.
 *
 * @return
 */
const unsigned int ReportPanTiltMotionProfile::Body::getSize()
{
	unsigned int size = 0;

	size += m_PanTiltMotionProfileRec.getSize();

	return size;
}

void ReportPanTiltMotionProfile::Body::encode(unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	m_PanTiltMotionProfileRec.encode(bytes + pos);
	pos += m_PanTiltMotionProfileRec.getSize();
}

void ReportPanTiltMotionProfile::Body::decode(const unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	m_PanTiltMotionProfileRec.decode(bytes + pos);
	pos += m_PanTiltMotionProfileRec.getSize();
}

ReportPanTiltMotionProfile::Body &ReportPanTiltMotionProfile::Body::operator=(const Body &value)
{
	m_PanTiltMotionProfileRec = value.m_PanTiltMotionProfileRec;
	m_PanTiltMotionProfileRec.setParent(this);
	/// This code is currently not supported

	return *this;
}

bool ReportPanTiltMotionProfile::Body::operator==(const Body &value) const
{
	if (m_PanTiltMotionProfileRec != value.m_PanTiltMotionProfileRec)
	{
		return false;
	}
	/// This code is currently not supported
	return true;
}

bool ReportPanTiltMotionProfile::Body::operator!=(const Body &value) const
{
	return !((*this) == value);
}

ReportPanTiltMotionProfile::Body::Body()
{
	m_PanTiltMotionProfileRec.setParent(this);
	/// No Initialization of m_PanTiltMotionProfileRec necessary.
}

ReportPanTiltMotionProfile::Body::Body(const Body &value)
{
	/// Initiliaze the protected variables
	m_PanTiltMotionProfileRec.setParent(this);
	/// No Initialization of m_PanTiltMotionProfileRec necessary.

	/// Copy the values
	m_PanTiltMotionProfileRec = value.m_PanTiltMotionProfileRec;
	m_PanTiltMotionProfileRec.setParent(this);
	/// This code is currently not supported
}

ReportPanTiltMotionProfile::Body::~Body()
{
}

ReportPanTiltMotionProfile::Body* const ReportPanTiltMotionProfile::getBody()
{
	return &m_Body;
}

int ReportPanTiltMotionProfile::setBody(const Body &value)
{
	m_Body = value;
	return 0;
}

/**
 * Returns the size of memory the used data members of the class occupies.
 * This is not necessarily the same size of memory the class actually occupies.
 * Eg. A union of an int and a double may occupy 8 bytes. However, if the data
 *     stored is an int, this function will return a size of 4 bytes.
 *
 * @return
 */
const unsigned int ReportPanTiltMotionProfile::getSize()
{
	unsigned int size = 0;

	size += m_AppHeader.getSize();
	size += m_Body.getSize();

	return size;
}

void ReportPanTiltMotionProfile::encode(unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	m_AppHeader.encode(bytes + pos);
	pos += m_AppHeader.getSize();
	m_Body.encode(bytes + pos);
	pos += m_Body.getSize();
}

void ReportPanTiltMotionProfile::decode(const unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	m_AppHeader.decode(bytes + pos);
	pos += m_AppHeader.getSize();
	m_Body.decode(bytes + pos);
	pos += m_Body.getSize();
}

ReportPanTiltMotionProfile &ReportPanTiltMotionProfile::operator=(const ReportPanTiltMotionProfile &value)
{
	m_AppHeader = value.m_AppHeader;
	m_Body = value.m_Body;

	return *this;
}

bool ReportPanTiltMotionProfile::operator==(const ReportPanTiltMotionProfile &value) const
{
	if (m_AppHeader != value.m_AppHeader)
	{
		return false;
	}
	if (m_Body != value.m_Body)
	{
		return false;
	}

	return true;
}

bool ReportPanTiltMotionProfile::operator!=(const ReportPanTiltMotionProfile &value) const
{
	return !((*this) == value);
}

ReportPanTiltMotionProfile::ReportPanTiltMotionProfile()
{
	/// No Initialization of m_AppHeader necessary.
	/// No Initialization of m_Body necessary.
	m_IsCommand = false;
}

ReportPanTiltMotionProfile::ReportPanTiltMotionProfile(const ReportPanTiltMotionProfile &value)
{
	/// Initiliaze the protected variables
	/// No Initialization of m_AppHeader necessary.
	/// No Initialization of m_Body necessary.
	m_IsCommand = false;

	/// Copy the values
	m_AppHeader = value.m_AppHeader;
	m_Body = value.m_Body;
}

ReportPanTiltMotionProfile::~ReportPanTiltMotionProfile()
{
}


}
