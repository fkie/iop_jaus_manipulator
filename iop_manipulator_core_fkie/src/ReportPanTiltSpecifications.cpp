#include "iop_manipulator_core_fkie/ReportPanTiltSpecifications.h"

namespace iop_manipulator_core_fkie
{

void ReportPanTiltSpecifications::AppHeader::HeaderRec::setParent(AppHeader* parent)
{
	m_parent = parent;
}

void ReportPanTiltSpecifications::AppHeader::HeaderRec::setParentPresenceVector()
{
	if(m_parent != NULL )
	{
		m_parent->setParentPresenceVector();
	}
}

jUnsignedShortInteger ReportPanTiltSpecifications::AppHeader::HeaderRec::getMessageID()
{
	return m_MessageID;
}

int ReportPanTiltSpecifications::AppHeader::HeaderRec::setMessageID(jUnsignedShortInteger value)
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
const unsigned int ReportPanTiltSpecifications::AppHeader::HeaderRec::getSize()
{
	unsigned int size = 0;

	size += sizeof(jUnsignedShortInteger);

	return size;
}

void ReportPanTiltSpecifications::AppHeader::HeaderRec::encode(unsigned char *bytes)
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

void ReportPanTiltSpecifications::AppHeader::HeaderRec::decode(const unsigned char *bytes)
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

ReportPanTiltSpecifications::AppHeader::HeaderRec &ReportPanTiltSpecifications::AppHeader::HeaderRec::operator=(const HeaderRec &value)
{
	m_MessageID = value.m_MessageID;

	return *this;
}

bool ReportPanTiltSpecifications::AppHeader::HeaderRec::operator==(const HeaderRec &value) const
{
	if (m_MessageID != value.m_MessageID)
	{
		return false;
	}

	return true;
}

bool ReportPanTiltSpecifications::AppHeader::HeaderRec::operator!=(const HeaderRec &value) const
{
	return !((*this) == value);
}

ReportPanTiltSpecifications::AppHeader::HeaderRec::HeaderRec()
{
	m_parent = NULL;
	m_MessageID = 0x4620;
}

ReportPanTiltSpecifications::AppHeader::HeaderRec::HeaderRec(const HeaderRec &value)
{
	/// Initiliaze the protected variables
	m_parent = NULL;
	m_MessageID = 0x4620;

	/// Copy the values
	m_MessageID = value.m_MessageID;
}

ReportPanTiltSpecifications::AppHeader::HeaderRec::~HeaderRec()
{
}

ReportPanTiltSpecifications::AppHeader::HeaderRec* const ReportPanTiltSpecifications::AppHeader::getHeaderRec()
{
	return &m_HeaderRec;
}

int ReportPanTiltSpecifications::AppHeader::setHeaderRec(const HeaderRec &value)
{
	m_HeaderRec = value;
	setParentPresenceVector();
	return 0;
}

void ReportPanTiltSpecifications::AppHeader::setParentPresenceVector()
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
const unsigned int ReportPanTiltSpecifications::AppHeader::getSize()
{
	unsigned int size = 0;

	size += m_HeaderRec.getSize();

	return size;
}

void ReportPanTiltSpecifications::AppHeader::encode(unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	m_HeaderRec.encode(bytes + pos);
	pos += m_HeaderRec.getSize();
}

void ReportPanTiltSpecifications::AppHeader::decode(const unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	m_HeaderRec.decode(bytes + pos);
	pos += m_HeaderRec.getSize();
}

ReportPanTiltSpecifications::AppHeader &ReportPanTiltSpecifications::AppHeader::operator=(const AppHeader &value)
{
	m_HeaderRec = value.m_HeaderRec;
	m_HeaderRec.setParent(this);

	return *this;
}

bool ReportPanTiltSpecifications::AppHeader::operator==(const AppHeader &value) const
{
	if (m_HeaderRec != value.m_HeaderRec)
	{
		return false;
	}
	return true;
}

bool ReportPanTiltSpecifications::AppHeader::operator!=(const AppHeader &value) const
{
	return !((*this) == value);
}

ReportPanTiltSpecifications::AppHeader::AppHeader()
{
	m_HeaderRec.setParent(this);
	/// No Initialization of m_HeaderRec necessary.
}

ReportPanTiltSpecifications::AppHeader::AppHeader(const AppHeader &value)
{
	/// Initiliaze the protected variables
	m_HeaderRec.setParent(this);
	/// No Initialization of m_HeaderRec necessary.

	/// Copy the values
	m_HeaderRec = value.m_HeaderRec;
	m_HeaderRec.setParent(this);
}

ReportPanTiltSpecifications::AppHeader::~AppHeader()
{
}

ReportPanTiltSpecifications::AppHeader* const ReportPanTiltSpecifications::getAppHeader()
{
	return &m_AppHeader;
}

int ReportPanTiltSpecifications::setAppHeader(const AppHeader &value)
{
	m_AppHeader = value;
	return 0;
}

void ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setParent(Body* parent)
{
	m_parent = parent;
}

void ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setParentPresenceVector()
{
	if(m_parent != NULL )
	{
		m_parent->setParentPresenceVector();
	}
}

jUnsignedByte ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getPresenceVector()
{
	return m_PresenceVector;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setPresenceVector(unsigned int index)
{
	std::bitset<sizeof(jUnsignedByte) * 8> pvBitSet((int)(m_PresenceVector));

	pvBitSet[index] = 1;
	m_PresenceVector = (jUnsignedByte)pvBitSet.to_ulong();
	return 0;
}

bool ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::checkPresenceVector(unsigned int index) const
{
	std::bitset<sizeof(jUnsignedByte) * 8> pvBitSet((int)(m_PresenceVector));

	return (pvBitSet[index] == 1);
}

bool ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::isPanTiltCoordinateSysXValid() const
{
	if (checkPresenceVector(0))
	{
		return true;
	}
	return false;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getPanTiltCoordinateSysX()
{
	double value;

	double scaleFactor = ( 30.0 - -30.0 ) / 4.294967295E9;
	double bias = -30.0;

	value = m_PanTiltCoordinateSysX * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setPanTiltCoordinateSysX(double value)
{
	if ((value >= -30.0) && (value <= 30.0))
	{
		double scaleFactor = ( 30.0 - -30.0 ) / 4.294967295E9;
		double bias = -30.0;

		m_PanTiltCoordinateSysX= (jUnsignedInteger)((value - bias) / scaleFactor);
		setPresenceVector(0);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

bool ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::isPanTiltCoordinateSysYValid() const
{
	if (checkPresenceVector(1))
	{
		return true;
	}
	return false;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getPanTiltCoordinateSysY()
{
	double value;

	double scaleFactor = ( 30.0 - -30.0 ) / 4.294967295E9;
	double bias = -30.0;

	value = m_PanTiltCoordinateSysY * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setPanTiltCoordinateSysY(double value)
{
	if ((value >= -30.0) && (value <= 30.0))
	{
		double scaleFactor = ( 30.0 - -30.0 ) / 4.294967295E9;
		double bias = -30.0;

		m_PanTiltCoordinateSysY= (jUnsignedInteger)((value - bias) / scaleFactor);
		setPresenceVector(1);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

bool ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::isPanTiltCoordinateSysZValid() const
{
	if (checkPresenceVector(2))
	{
		return true;
	}
	return false;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getPanTiltCoordinateSysZ()
{
	double value;

	double scaleFactor = ( 30.0 - -30.0 ) / 4.294967295E9;
	double bias = -30.0;

	value = m_PanTiltCoordinateSysZ * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setPanTiltCoordinateSysZ(double value)
{
	if ((value >= -30.0) && (value <= 30.0))
	{
		double scaleFactor = ( 30.0 - -30.0 ) / 4.294967295E9;
		double bias = -30.0;

		m_PanTiltCoordinateSysZ= (jUnsignedInteger)((value - bias) / scaleFactor);
		setPresenceVector(2);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

bool ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::isDComponentOfUnitQuaternionQValid() const
{
	if (checkPresenceVector(3))
	{
		return true;
	}
	return false;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getDComponentOfUnitQuaternionQ()
{
	double value;

	double scaleFactor = ( 1.0 - -1.0 ) / 4.294967295E9;
	double bias = -1.0;

	value = m_DComponentOfUnitQuaternionQ * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setDComponentOfUnitQuaternionQ(double value)
{
	if ((value >= -1.0) && (value <= 1.0))
	{
		double scaleFactor = ( 1.0 - -1.0 ) / 4.294967295E9;
		double bias = -1.0;

		m_DComponentOfUnitQuaternionQ= (jUnsignedInteger)((value - bias) / scaleFactor);
		setPresenceVector(3);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

bool ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::isAComponentOfUnitQuaternionQValid() const
{
	if (checkPresenceVector(4))
	{
		return true;
	}
	return false;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getAComponentOfUnitQuaternionQ()
{
	double value;

	double scaleFactor = ( 1.0 - -1.0 ) / 4.294967295E9;
	double bias = -1.0;

	value = m_AComponentOfUnitQuaternionQ * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setAComponentOfUnitQuaternionQ(double value)
{
	if ((value >= -1.0) && (value <= 1.0))
	{
		double scaleFactor = ( 1.0 - -1.0 ) / 4.294967295E9;
		double bias = -1.0;

		m_AComponentOfUnitQuaternionQ= (jUnsignedInteger)((value - bias) / scaleFactor);
		setPresenceVector(4);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

bool ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::isBComponentOfUnitQuaternionQValid() const
{
	if (checkPresenceVector(5))
	{
		return true;
	}
	return false;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getBComponentOfUnitQuaternionQ()
{
	double value;

	double scaleFactor = ( 1.0 - -1.0 ) / 4.294967295E9;
	double bias = -1.0;

	value = m_BComponentOfUnitQuaternionQ * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setBComponentOfUnitQuaternionQ(double value)
{
	if ((value >= -1.0) && (value <= 1.0))
	{
		double scaleFactor = ( 1.0 - -1.0 ) / 4.294967295E9;
		double bias = -1.0;

		m_BComponentOfUnitQuaternionQ= (jUnsignedInteger)((value - bias) / scaleFactor);
		setPresenceVector(5);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

bool ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::isCComponentOfUnitQuaternionQValid() const
{
	if (checkPresenceVector(6))
	{
		return true;
	}
	return false;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getCComponentOfUnitQuaternionQ()
{
	double value;

	double scaleFactor = ( 1.0 - -1.0 ) / 4.294967295E9;
	double bias = -1.0;

	value = m_CComponentOfUnitQuaternionQ * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setCComponentOfUnitQuaternionQ(double value)
{
	if ((value >= -1.0) && (value <= 1.0))
	{
		double scaleFactor = ( 1.0 - -1.0 ) / 4.294967295E9;
		double bias = -1.0;

		m_CComponentOfUnitQuaternionQ= (jUnsignedInteger)((value - bias) / scaleFactor);
		setPresenceVector(6);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getJoint1MinValue()
{
	double value;

	double scaleFactor = ( 8*3.14159265358979323846 - -8*3.14159265358979323846 ) / 4.294967295E9;
	double bias = -8*3.14159265358979323846;

	value = m_Joint1MinValue * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setJoint1MinValue(double value)
{
	if ((value >= -8*3.14159265358979323846) && (value <= 8*3.14159265358979323846))
	{
		double scaleFactor = ( 8*3.14159265358979323846 - -8*3.14159265358979323846 ) / 4.294967295E9;
		double bias = -8*3.14159265358979323846;

		m_Joint1MinValue= (jUnsignedInteger)((value - bias) / scaleFactor);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getJoint1MaxValue()
{
	double value;

	double scaleFactor = ( 8*3.14159265358979323846 - -8*3.14159265358979323846 ) / 4.294967295E9;
	double bias = -8*3.14159265358979323846;

	value = m_Joint1MaxValue * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setJoint1MaxValue(double value)
{
	if ((value >= -8*3.14159265358979323846) && (value <= 8*3.14159265358979323846))
	{
		double scaleFactor = ( 8*3.14159265358979323846 - -8*3.14159265358979323846 ) / 4.294967295E9;
		double bias = -8*3.14159265358979323846;

		m_Joint1MaxValue= (jUnsignedInteger)((value - bias) / scaleFactor);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getJoint1MaxSpeed()
{
	double value;

	double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
	double bias = 0.0;

	value = m_Joint1MaxSpeed * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setJoint1MaxSpeed(double value)
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

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getJoint2MinValue()
{
	double value;

	double scaleFactor = ( 8*3.14159265358979323846 - -8*3.14159265358979323846 ) / 4.294967295E9;
	double bias = -8*3.14159265358979323846;

	value = m_Joint2MinValue * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setJoint2MinValue(double value)
{
	if ((value >= -8*3.14159265358979323846) && (value <= 8*3.14159265358979323846))
	{
		double scaleFactor = ( 8*3.14159265358979323846 - -8*3.14159265358979323846 ) / 4.294967295E9;
		double bias = -8*3.14159265358979323846;

		m_Joint2MinValue= (jUnsignedInteger)((value - bias) / scaleFactor);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getJoint2MaxValue()
{
	double value;

	double scaleFactor = ( 8*3.14159265358979323846 - -8*3.14159265358979323846 ) / 4.294967295E9;
	double bias = -8*3.14159265358979323846;

	value = m_Joint2MaxValue * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setJoint2MaxValue(double value)
{
	if ((value >= -8*3.14159265358979323846) && (value <= 8*3.14159265358979323846))
	{
		double scaleFactor = ( 8*3.14159265358979323846 - -8*3.14159265358979323846 ) / 4.294967295E9;
		double bias = -8*3.14159265358979323846;

		m_Joint2MaxValue= (jUnsignedInteger)((value - bias) / scaleFactor);
		setParentPresenceVector();
		return 0;
	}
	return 1;
}

double ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getJoint2MaxSpeed()
{
	double value;

	double scaleFactor = ( 10*3.14159265358979323846 - 0.0 ) / 4.294967295E9;
	double bias = 0.0;

	value = m_Joint2MaxSpeed * scaleFactor + bias;

	return value;
}

int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::setJoint2MaxSpeed(double value)
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

/**
 * Returns the size of memory the used data members of the class occupies.
 * This is not necessarily the same size of memory the class actually occupies.
 * Eg. A union of an int and a double may occupy 8 bytes. However, if the data
 *     stored is an int, this function will return a size of 4 bytes.
 *
 * @return
 */
const unsigned int ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::getSize()
{
	unsigned int size = 0;

	size += sizeof(jUnsignedByte);
	if (checkPresenceVector(0))
	{
		size += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(1))
	{
		size += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(2))
	{
		size += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(3))
	{
		size += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(4))
	{
		size += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(5))
	{
		size += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(6))
	{
		size += sizeof(jUnsignedInteger);
	}
	size += sizeof(jUnsignedInteger);
	size += sizeof(jUnsignedInteger);
	size += sizeof(jUnsignedInteger);
	size += sizeof(jUnsignedInteger);
	size += sizeof(jUnsignedInteger);
	size += sizeof(jUnsignedInteger);

	return size;
}

void ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::encode(unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	jUnsignedByte m_PresenceVectorTemp;

	m_PresenceVectorTemp = JSIDL_v_1_0::correctEndianness(m_PresenceVector);
	memcpy(bytes + pos, &m_PresenceVectorTemp, sizeof(jUnsignedByte));
	pos += sizeof(jUnsignedByte);
	if (checkPresenceVector(0))
	{
		jUnsignedInteger m_PanTiltCoordinateSysXTemp;

		m_PanTiltCoordinateSysXTemp = JSIDL_v_1_0::correctEndianness(m_PanTiltCoordinateSysX);
		memcpy(bytes + pos, &m_PanTiltCoordinateSysXTemp, sizeof(jUnsignedInteger));
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(1))
	{
		jUnsignedInteger m_PanTiltCoordinateSysYTemp;

		m_PanTiltCoordinateSysYTemp = JSIDL_v_1_0::correctEndianness(m_PanTiltCoordinateSysY);
		memcpy(bytes + pos, &m_PanTiltCoordinateSysYTemp, sizeof(jUnsignedInteger));
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(2))
	{
		jUnsignedInteger m_PanTiltCoordinateSysZTemp;

		m_PanTiltCoordinateSysZTemp = JSIDL_v_1_0::correctEndianness(m_PanTiltCoordinateSysZ);
		memcpy(bytes + pos, &m_PanTiltCoordinateSysZTemp, sizeof(jUnsignedInteger));
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(3))
	{
		jUnsignedInteger m_DComponentOfUnitQuaternionQTemp;

		m_DComponentOfUnitQuaternionQTemp = JSIDL_v_1_0::correctEndianness(m_DComponentOfUnitQuaternionQ);
		memcpy(bytes + pos, &m_DComponentOfUnitQuaternionQTemp, sizeof(jUnsignedInteger));
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(4))
	{
		jUnsignedInteger m_AComponentOfUnitQuaternionQTemp;

		m_AComponentOfUnitQuaternionQTemp = JSIDL_v_1_0::correctEndianness(m_AComponentOfUnitQuaternionQ);
		memcpy(bytes + pos, &m_AComponentOfUnitQuaternionQTemp, sizeof(jUnsignedInteger));
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(5))
	{
		jUnsignedInteger m_BComponentOfUnitQuaternionQTemp;

		m_BComponentOfUnitQuaternionQTemp = JSIDL_v_1_0::correctEndianness(m_BComponentOfUnitQuaternionQ);
		memcpy(bytes + pos, &m_BComponentOfUnitQuaternionQTemp, sizeof(jUnsignedInteger));
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(6))
	{
		jUnsignedInteger m_CComponentOfUnitQuaternionQTemp;

		m_CComponentOfUnitQuaternionQTemp = JSIDL_v_1_0::correctEndianness(m_CComponentOfUnitQuaternionQ);
		memcpy(bytes + pos, &m_CComponentOfUnitQuaternionQTemp, sizeof(jUnsignedInteger));
		pos += sizeof(jUnsignedInteger);
	}
	jUnsignedInteger m_Joint1MinValueTemp;

	m_Joint1MinValueTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MinValue);
	memcpy(bytes + pos, &m_Joint1MinValueTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint1MaxValueTemp;

	m_Joint1MaxValueTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxValue);
	memcpy(bytes + pos, &m_Joint1MaxValueTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint1MaxSpeedTemp;

	m_Joint1MaxSpeedTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxSpeed);
	memcpy(bytes + pos, &m_Joint1MaxSpeedTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MinValueTemp;

	m_Joint2MinValueTemp = JSIDL_v_1_0::correctEndianness(m_Joint2MinValue);
	memcpy(bytes + pos, &m_Joint2MinValueTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MaxValueTemp;

	m_Joint2MaxValueTemp = JSIDL_v_1_0::correctEndianness(m_Joint2MaxValue);
	memcpy(bytes + pos, &m_Joint2MaxValueTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MaxSpeedTemp;

	m_Joint2MaxSpeedTemp = JSIDL_v_1_0::correctEndianness(m_Joint2MaxSpeed);
	memcpy(bytes + pos, &m_Joint2MaxSpeedTemp, sizeof(jUnsignedInteger));
	pos += sizeof(jUnsignedInteger);
}

void ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::decode(const unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	jUnsignedByte m_PresenceVectorTemp;

	memcpy(&m_PresenceVectorTemp, bytes + pos, sizeof(jUnsignedByte));
	m_PresenceVector = JSIDL_v_1_0::correctEndianness(m_PresenceVectorTemp);
	pos += sizeof(jUnsignedByte);
	if (checkPresenceVector(0))
	{
		jUnsignedInteger m_PanTiltCoordinateSysXTemp;

		memcpy(&m_PanTiltCoordinateSysXTemp, bytes + pos, sizeof(jUnsignedInteger));
		m_PanTiltCoordinateSysX = JSIDL_v_1_0::correctEndianness(m_PanTiltCoordinateSysXTemp);
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(1))
	{
		jUnsignedInteger m_PanTiltCoordinateSysYTemp;

		memcpy(&m_PanTiltCoordinateSysYTemp, bytes + pos, sizeof(jUnsignedInteger));
		m_PanTiltCoordinateSysY = JSIDL_v_1_0::correctEndianness(m_PanTiltCoordinateSysYTemp);
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(2))
	{
		jUnsignedInteger m_PanTiltCoordinateSysZTemp;

		memcpy(&m_PanTiltCoordinateSysZTemp, bytes + pos, sizeof(jUnsignedInteger));
		m_PanTiltCoordinateSysZ = JSIDL_v_1_0::correctEndianness(m_PanTiltCoordinateSysZTemp);
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(3))
	{
		jUnsignedInteger m_DComponentOfUnitQuaternionQTemp;

		memcpy(&m_DComponentOfUnitQuaternionQTemp, bytes + pos, sizeof(jUnsignedInteger));
		m_DComponentOfUnitQuaternionQ = JSIDL_v_1_0::correctEndianness(m_DComponentOfUnitQuaternionQTemp);
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(4))
	{
		jUnsignedInteger m_AComponentOfUnitQuaternionQTemp;

		memcpy(&m_AComponentOfUnitQuaternionQTemp, bytes + pos, sizeof(jUnsignedInteger));
		m_AComponentOfUnitQuaternionQ = JSIDL_v_1_0::correctEndianness(m_AComponentOfUnitQuaternionQTemp);
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(5))
	{
		jUnsignedInteger m_BComponentOfUnitQuaternionQTemp;

		memcpy(&m_BComponentOfUnitQuaternionQTemp, bytes + pos, sizeof(jUnsignedInteger));
		m_BComponentOfUnitQuaternionQ = JSIDL_v_1_0::correctEndianness(m_BComponentOfUnitQuaternionQTemp);
		pos += sizeof(jUnsignedInteger);
	}
	if (checkPresenceVector(6))
	{
		jUnsignedInteger m_CComponentOfUnitQuaternionQTemp;

		memcpy(&m_CComponentOfUnitQuaternionQTemp, bytes + pos, sizeof(jUnsignedInteger));
		m_CComponentOfUnitQuaternionQ = JSIDL_v_1_0::correctEndianness(m_CComponentOfUnitQuaternionQTemp);
		pos += sizeof(jUnsignedInteger);
	}
	jUnsignedInteger m_Joint1MinValueTemp;

	memcpy(&m_Joint1MinValueTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint1MinValue = JSIDL_v_1_0::correctEndianness(m_Joint1MinValueTemp);
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint1MaxValueTemp;

	memcpy(&m_Joint1MaxValueTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint1MaxValue = JSIDL_v_1_0::correctEndianness(m_Joint1MaxValueTemp);
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint1MaxSpeedTemp;

	memcpy(&m_Joint1MaxSpeedTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint1MaxSpeed = JSIDL_v_1_0::correctEndianness(m_Joint1MaxSpeedTemp);
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MinValueTemp;

	memcpy(&m_Joint2MinValueTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint2MinValue = JSIDL_v_1_0::correctEndianness(m_Joint2MinValueTemp);
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MaxValueTemp;

	memcpy(&m_Joint2MaxValueTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint2MaxValue = JSIDL_v_1_0::correctEndianness(m_Joint2MaxValueTemp);
	pos += sizeof(jUnsignedInteger);
	jUnsignedInteger m_Joint2MaxSpeedTemp;

	memcpy(&m_Joint2MaxSpeedTemp, bytes + pos, sizeof(jUnsignedInteger));
	m_Joint2MaxSpeed = JSIDL_v_1_0::correctEndianness(m_Joint2MaxSpeedTemp);
	pos += sizeof(jUnsignedInteger);
}

ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec &ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::operator=(const ReportPanTiltSpecificationsRec &value)
{
	m_PresenceVector = value.m_PresenceVector;
	m_PanTiltCoordinateSysX = value.m_PanTiltCoordinateSysX;
	m_PanTiltCoordinateSysY = value.m_PanTiltCoordinateSysY;
	m_PanTiltCoordinateSysZ = value.m_PanTiltCoordinateSysZ;
	m_DComponentOfUnitQuaternionQ = value.m_DComponentOfUnitQuaternionQ;
	m_AComponentOfUnitQuaternionQ = value.m_AComponentOfUnitQuaternionQ;
	m_BComponentOfUnitQuaternionQ = value.m_BComponentOfUnitQuaternionQ;
	m_CComponentOfUnitQuaternionQ = value.m_CComponentOfUnitQuaternionQ;
	m_Joint1MinValue = value.m_Joint1MinValue;
	m_Joint1MaxValue = value.m_Joint1MaxValue;
	m_Joint1MaxSpeed = value.m_Joint1MaxSpeed;
	m_Joint2MinValue = value.m_Joint2MinValue;
	m_Joint2MaxValue = value.m_Joint2MaxValue;
	m_Joint2MaxSpeed = value.m_Joint2MaxSpeed;

	return *this;
}

bool ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::operator==(const ReportPanTiltSpecificationsRec &value) const
{
	if (m_PresenceVector != value.m_PresenceVector)
	{
		return false;
	}
	if (m_PanTiltCoordinateSysX != value.m_PanTiltCoordinateSysX)
	{
		return false;
	}
	if (m_PanTiltCoordinateSysY != value.m_PanTiltCoordinateSysY)
	{
		return false;
	}
	if (m_PanTiltCoordinateSysZ != value.m_PanTiltCoordinateSysZ)
	{
		return false;
	}
	if (m_DComponentOfUnitQuaternionQ != value.m_DComponentOfUnitQuaternionQ)
	{
		return false;
	}
	if (m_AComponentOfUnitQuaternionQ != value.m_AComponentOfUnitQuaternionQ)
	{
		return false;
	}
	if (m_BComponentOfUnitQuaternionQ != value.m_BComponentOfUnitQuaternionQ)
	{
		return false;
	}
	if (m_CComponentOfUnitQuaternionQ != value.m_CComponentOfUnitQuaternionQ)
	{
		return false;
	}
	if (m_Joint1MinValue != value.m_Joint1MinValue)
	{
		return false;
	}
	if (m_Joint1MaxValue != value.m_Joint1MaxValue)
	{
		return false;
	}
	if (m_Joint1MaxSpeed != value.m_Joint1MaxSpeed)
	{
		return false;
	}
	if (m_Joint2MinValue != value.m_Joint2MinValue)
	{
		return false;
	}
	if (m_Joint2MaxValue != value.m_Joint2MaxValue)
	{
		return false;
	}
	if (m_Joint2MaxSpeed != value.m_Joint2MaxSpeed)
	{
		return false;
	}

	return true;
}

bool ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::operator!=(const ReportPanTiltSpecificationsRec &value) const
{
	return !((*this) == value);
}

ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::ReportPanTiltSpecificationsRec()
{
	m_parent = NULL;
	m_PresenceVector = 0;
	m_PanTiltCoordinateSysX = 0;
	m_PanTiltCoordinateSysY = 0;
	m_PanTiltCoordinateSysZ = 0;
	m_DComponentOfUnitQuaternionQ = 0;
	m_AComponentOfUnitQuaternionQ = 0;
	m_BComponentOfUnitQuaternionQ = 0;
	m_CComponentOfUnitQuaternionQ = 0;
	m_Joint1MinValue = 0;
	m_Joint1MaxValue = 0;
	m_Joint1MaxSpeed = 0;
	m_Joint2MinValue = 0;
	m_Joint2MaxValue = 0;
	m_Joint2MaxSpeed = 0;
}

ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::ReportPanTiltSpecificationsRec(const ReportPanTiltSpecificationsRec &value)
{
	/// Initiliaze the protected variables
	m_parent = NULL;
	m_PresenceVector = 0;
	m_PanTiltCoordinateSysX = 0;
	m_PanTiltCoordinateSysY = 0;
	m_PanTiltCoordinateSysZ = 0;
	m_DComponentOfUnitQuaternionQ = 0;
	m_AComponentOfUnitQuaternionQ = 0;
	m_BComponentOfUnitQuaternionQ = 0;
	m_CComponentOfUnitQuaternionQ = 0;
	m_Joint1MinValue = 0;
	m_Joint1MaxValue = 0;
	m_Joint1MaxSpeed = 0;
	m_Joint2MinValue = 0;
	m_Joint2MaxValue = 0;
	m_Joint2MaxSpeed = 0;

	/// Copy the values
	m_PresenceVector = value.m_PresenceVector;
	m_PanTiltCoordinateSysX = value.m_PanTiltCoordinateSysX;
	m_PanTiltCoordinateSysY = value.m_PanTiltCoordinateSysY;
	m_PanTiltCoordinateSysZ = value.m_PanTiltCoordinateSysZ;
	m_DComponentOfUnitQuaternionQ = value.m_DComponentOfUnitQuaternionQ;
	m_AComponentOfUnitQuaternionQ = value.m_AComponentOfUnitQuaternionQ;
	m_BComponentOfUnitQuaternionQ = value.m_BComponentOfUnitQuaternionQ;
	m_CComponentOfUnitQuaternionQ = value.m_CComponentOfUnitQuaternionQ;
	m_Joint1MinValue = value.m_Joint1MinValue;
	m_Joint1MaxValue = value.m_Joint1MaxValue;
	m_Joint1MaxSpeed = value.m_Joint1MaxSpeed;
	m_Joint2MinValue = value.m_Joint2MinValue;
	m_Joint2MaxValue = value.m_Joint2MaxValue;
	m_Joint2MaxSpeed = value.m_Joint2MaxSpeed;
}

ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec::~ReportPanTiltSpecificationsRec()
{
}

ReportPanTiltSpecifications::Body::ReportPanTiltSpecificationsRec* const ReportPanTiltSpecifications::Body::getReportPanTiltSpecificationsRec()
{
	return &m_ReportPanTiltSpecificationsRec;
}

int ReportPanTiltSpecifications::Body::setReportPanTiltSpecificationsRec(const ReportPanTiltSpecificationsRec &value)
{
	m_ReportPanTiltSpecificationsRec = value;
	setParentPresenceVector();
	return 0;
}

void ReportPanTiltSpecifications::Body::setParentPresenceVector()
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
const unsigned int ReportPanTiltSpecifications::Body::getSize()
{
	unsigned int size = 0;

	size += m_ReportPanTiltSpecificationsRec.getSize();

	return size;
}

void ReportPanTiltSpecifications::Body::encode(unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	m_ReportPanTiltSpecificationsRec.encode(bytes + pos);
	pos += m_ReportPanTiltSpecificationsRec.getSize();
}

void ReportPanTiltSpecifications::Body::decode(const unsigned char *bytes)
{

	if (bytes == NULL)
	{
		return;
	}

	int pos = 0;
	m_ReportPanTiltSpecificationsRec.decode(bytes + pos);
	pos += m_ReportPanTiltSpecificationsRec.getSize();
}

ReportPanTiltSpecifications::Body &ReportPanTiltSpecifications::Body::operator=(const Body &value)
{
	m_ReportPanTiltSpecificationsRec = value.m_ReportPanTiltSpecificationsRec;
	m_ReportPanTiltSpecificationsRec.setParent(this);
	/// This code is currently not supported

	return *this;
}

bool ReportPanTiltSpecifications::Body::operator==(const Body &value) const
{
	if (m_ReportPanTiltSpecificationsRec != value.m_ReportPanTiltSpecificationsRec)
	{
		return false;
	}
	/// This code is currently not supported
	return true;
}

bool ReportPanTiltSpecifications::Body::operator!=(const Body &value) const
{
	return !((*this) == value);
}

ReportPanTiltSpecifications::Body::Body()
{
	m_ReportPanTiltSpecificationsRec.setParent(this);
	/// No Initialization of m_ReportPanTiltSpecificationsRec necessary.
}

ReportPanTiltSpecifications::Body::Body(const Body &value)
{
	/// Initiliaze the protected variables
	m_ReportPanTiltSpecificationsRec.setParent(this);
	/// No Initialization of m_ReportPanTiltSpecificationsRec necessary.

	/// Copy the values
	m_ReportPanTiltSpecificationsRec = value.m_ReportPanTiltSpecificationsRec;
	m_ReportPanTiltSpecificationsRec.setParent(this);
	/// This code is currently not supported
}

ReportPanTiltSpecifications::Body::~Body()
{
}

ReportPanTiltSpecifications::Body* const ReportPanTiltSpecifications::getBody()
{
	return &m_Body;
}

int ReportPanTiltSpecifications::setBody(const Body &value)
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
const unsigned int ReportPanTiltSpecifications::getSize()
{
	unsigned int size = 0;

	size += m_AppHeader.getSize();
	size += m_Body.getSize();

	return size;
}

void ReportPanTiltSpecifications::encode(unsigned char *bytes)
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

void ReportPanTiltSpecifications::decode(const unsigned char *bytes)
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

ReportPanTiltSpecifications &ReportPanTiltSpecifications::operator=(const ReportPanTiltSpecifications &value)
{
	m_AppHeader = value.m_AppHeader;
	m_Body = value.m_Body;

	return *this;
}

bool ReportPanTiltSpecifications::operator==(const ReportPanTiltSpecifications &value) const
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

bool ReportPanTiltSpecifications::operator!=(const ReportPanTiltSpecifications &value) const
{
	return !((*this) == value);
}

ReportPanTiltSpecifications::ReportPanTiltSpecifications()
{
	/// No Initialization of m_AppHeader necessary.
	/// No Initialization of m_Body necessary.
	m_IsCommand = false;
}

ReportPanTiltSpecifications::ReportPanTiltSpecifications(const ReportPanTiltSpecifications &value)
{
	/// Initiliaze the protected variables
	/// No Initialization of m_AppHeader necessary.
	/// No Initialization of m_Body necessary.
	m_IsCommand = false;

	/// Copy the values
	m_AppHeader = value.m_AppHeader;
	m_Body = value.m_Body;
}

ReportPanTiltSpecifications::~ReportPanTiltSpecifications()
{
}


}
