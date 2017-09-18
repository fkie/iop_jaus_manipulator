#include "iop_manipulator_core_fkie/ReportManipulatorSpecifications.h"
#include <ros/console.h>
namespace iop_manipulator_core_fkie
{

void ReportManipulatorSpecifications::AppHeader::HeaderRec::setParent(AppHeader* parent)
{
  m_parent = parent;
}

void ReportManipulatorSpecifications::AppHeader::HeaderRec::setParentPresenceVector()
{
  if (m_parent != NULL)
  {
    m_parent->setParentPresenceVector();
  }
}

jUnsignedShortInteger ReportManipulatorSpecifications::AppHeader::HeaderRec::getMessageID()
{
  return m_MessageID;
}

int ReportManipulatorSpecifications::AppHeader::HeaderRec::setMessageID(jUnsignedShortInteger value)
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
const unsigned int ReportManipulatorSpecifications::AppHeader::HeaderRec::getSize()
{
  unsigned int size = 0;

  size += sizeof(jUnsignedShortInteger);

  return size;
}

void ReportManipulatorSpecifications::AppHeader::HeaderRec::encode(unsigned char *bytes)
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

void ReportManipulatorSpecifications::AppHeader::HeaderRec::decode(const unsigned char *bytes)
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

ReportManipulatorSpecifications::AppHeader::HeaderRec &ReportManipulatorSpecifications::AppHeader::HeaderRec::operator=(
    const HeaderRec &value)
{
  m_MessageID = value.m_MessageID;

  return *this;
}

bool ReportManipulatorSpecifications::AppHeader::HeaderRec::operator==(const HeaderRec &value) const
{
  if (m_MessageID != value.m_MessageID)
  {
    return false;
  }

  return true;
}

bool ReportManipulatorSpecifications::AppHeader::HeaderRec::operator!=(const HeaderRec &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::AppHeader::HeaderRec::HeaderRec()
{
  m_parent = NULL;
  m_MessageID = 0x4600;
}

ReportManipulatorSpecifications::AppHeader::HeaderRec::HeaderRec(const HeaderRec &value)
{
  /// Initiliaze the protected variables
  m_parent = NULL;
  m_MessageID = 0x4600;

  /// Copy the values
  m_MessageID = value.m_MessageID;
}

ReportManipulatorSpecifications::AppHeader::HeaderRec::~HeaderRec()
{
}

ReportManipulatorSpecifications::AppHeader::HeaderRec* const ReportManipulatorSpecifications::AppHeader::getHeaderRec()
{
  return &m_HeaderRec;
}

int ReportManipulatorSpecifications::AppHeader::setHeaderRec(const HeaderRec &value)
{
  m_HeaderRec = value;
  setParentPresenceVector();
  return 0;
}

void ReportManipulatorSpecifications::AppHeader::setParentPresenceVector()
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
const unsigned int ReportManipulatorSpecifications::AppHeader::getSize()
{
  unsigned int size = 0;

  size += m_HeaderRec.getSize();

  return size;
}

void ReportManipulatorSpecifications::AppHeader::encode(unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  m_HeaderRec.encode(bytes + pos);
  pos += m_HeaderRec.getSize();
}

void ReportManipulatorSpecifications::AppHeader::decode(const unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  m_HeaderRec.decode(bytes + pos);
  pos += m_HeaderRec.getSize();
}

ReportManipulatorSpecifications::AppHeader &ReportManipulatorSpecifications::AppHeader::operator=(
    const AppHeader &value)
{
  m_HeaderRec = value.m_HeaderRec;
  m_HeaderRec.setParent(this);

  return *this;
}

bool ReportManipulatorSpecifications::AppHeader::operator==(const AppHeader &value) const
{
  if (m_HeaderRec != value.m_HeaderRec)
  {
    return false;
  }
  return true;
}

bool ReportManipulatorSpecifications::AppHeader::operator!=(const AppHeader &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::AppHeader::AppHeader()
{
  m_HeaderRec.setParent(this);
  /// No Initialization of m_HeaderRec necessary.
}

ReportManipulatorSpecifications::AppHeader::AppHeader(const AppHeader &value)
{
  /// Initiliaze the protected variables
  m_HeaderRec.setParent(this);
  /// No Initialization of m_HeaderRec necessary.

  /// Copy the values
  m_HeaderRec = value.m_HeaderRec;
  m_HeaderRec.setParent(this);
}

ReportManipulatorSpecifications::AppHeader::~AppHeader()
{
}

ReportManipulatorSpecifications::AppHeader* const ReportManipulatorSpecifications::getAppHeader()
{
  return &m_AppHeader;
}

int ReportManipulatorSpecifications::setAppHeader(const AppHeader &value)
{
  m_AppHeader = value;
  return 0;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::setParent(Body* parent)
{
  m_parent = parent;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::setParentPresenceVector()
{
  if (m_parent != NULL)
  {
    m_parent->setParentPresenceVector();
  }
}

jUnsignedByte ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::getPresenceVector()
{
  return m_PresenceVector;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::setPresenceVector(unsigned int index)
{
  std::bitset < sizeof(jUnsignedByte) * 8 > pvBitSet((int)(m_PresenceVector));
  pvBitSet[index] = 1;
  m_PresenceVector = (jUnsignedByte)pvBitSet.to_ulong();
  return 0;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::checkPresenceVector(
    unsigned int index) const
{
  std::bitset < sizeof(jUnsignedByte) * 8 > pvBitSet((int)(m_PresenceVector));

  return (pvBitSet[index] == 1);
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::setParent(
    ReportManipulatorSpecification* parent)
{
  m_parent = parent;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::setParentPresenceVector()
{
  if (m_parent != NULL)
  {
    m_parent->setPresenceVector(0);
    m_parent->setParentPresenceVector();
  }
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::getManipulatorCoordinateSysX()
{
  double value;

  double scaleFactor = (30.0 - -30.0) / 4.294967295E9;
  double bias = -30.0;

  value = m_ManipulatorCoordinateSysX * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::setManipulatorCoordinateSysX(
    double value)
{
  if ((value >= -30.0) && (value <= 30.0))
  {
    double scaleFactor = (30.0 - -30.0) / 4.294967295E9;
    double bias = -30.0;

    m_ManipulatorCoordinateSysX = (jUnsignedInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::getManipulatorCoordinateSysY()
{
  double value;

  double scaleFactor = (30.0 - -30.0) / 4.294967295E9;
  double bias = -30.0;

  value = m_ManipulatorCoordinateSysY * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::setManipulatorCoordinateSysY(
    double value)
{
  if ((value >= -30.0) && (value <= 30.0))
  {
    double scaleFactor = (30.0 - -30.0) / 4.294967295E9;
    double bias = -30.0;

    m_ManipulatorCoordinateSysY = (jUnsignedInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::getManipulatorCoordinateSysZ()
{
  double value;

  double scaleFactor = (30.0 - -30.0) / 4.294967295E9;
  double bias = -30.0;

  value = m_ManipulatorCoordinateSysZ * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::setManipulatorCoordinateSysZ(
    double value)
{
  if ((value >= -30.0) && (value <= 30.0))
  {
    double scaleFactor = (30.0 - -30.0) / 4.294967295E9;
    double bias = -30.0;

    m_ManipulatorCoordinateSysZ = (jUnsignedInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::getDComponentOfUnitQuaternionQ()
{
  double value;

  double scaleFactor = (1.0 - -1.0) / 4.294967295E9;
  double bias = -1.0;

  value = m_DComponentOfUnitQuaternionQ * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::setDComponentOfUnitQuaternionQ(
    double value)
{
  if ((value >= -1.0) && (value <= 1.0))
  {
    double scaleFactor = (1.0 - -1.0) / 4.294967295E9;
    double bias = -1.0;

    m_DComponentOfUnitQuaternionQ = (jUnsignedInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::getAComponentOfUnitQuaternionQ()
{
  double value;

  double scaleFactor = (1.0 - -1.0) / 4.294967295E9;
  double bias = -1.0;

  value = m_AComponentOfUnitQuaternionQ * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::setAComponentOfUnitQuaternionQ(
    double value)
{
  if ((value >= -1.0) && (value <= 1.0))
  {
    double scaleFactor = (1.0 - -1.0) / 4.294967295E9;
    double bias = -1.0;

    m_AComponentOfUnitQuaternionQ = (jUnsignedInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::getBComponentOfUnitQuaternionQ()
{
  double value;

  double scaleFactor = (1.0 - -1.0) / 4.294967295E9;
  double bias = -1.0;

  value = m_BComponentOfUnitQuaternionQ * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::setBComponentOfUnitQuaternionQ(
    double value)
{
  if ((value >= -1.0) && (value <= 1.0))
  {
    double scaleFactor = (1.0 - -1.0) / 4.294967295E9;
    double bias = -1.0;

    m_BComponentOfUnitQuaternionQ = (jUnsignedInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::getCComponentOfUnitQuaternionQ()
{
  double value;

  double scaleFactor = (1.0 - -1.0) / 4.294967295E9;
  double bias = -1.0;

  value = m_CComponentOfUnitQuaternionQ * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::setCComponentOfUnitQuaternionQ(
    double value)
{
  if ((value >= -1.0) && (value <= 1.0))
  {
    double scaleFactor = (1.0 - -1.0) / 4.294967295E9;
    double bias = -1.0;

    m_CComponentOfUnitQuaternionQ = (jUnsignedInteger)((value - bias) / scaleFactor);
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
const unsigned int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::getSize()
{
  unsigned int size = 0;

  size += sizeof(jUnsignedInteger);
  size += sizeof(jUnsignedInteger);
  size += sizeof(jUnsignedInteger);
  size += sizeof(jUnsignedInteger);
  size += sizeof(jUnsignedInteger);
  size += sizeof(jUnsignedInteger);
  size += sizeof(jUnsignedInteger);

  return size;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::encode(
    unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  jUnsignedInteger m_ManipulatorCoordinateSysXTemp;

  m_ManipulatorCoordinateSysXTemp = JSIDL_v_1_0::correctEndianness(m_ManipulatorCoordinateSysX);
  memcpy(bytes + pos, &m_ManipulatorCoordinateSysXTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_ManipulatorCoordinateSysYTemp;

  m_ManipulatorCoordinateSysYTemp = JSIDL_v_1_0::correctEndianness(m_ManipulatorCoordinateSysY);
  memcpy(bytes + pos, &m_ManipulatorCoordinateSysYTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_ManipulatorCoordinateSysZTemp;

  m_ManipulatorCoordinateSysZTemp = JSIDL_v_1_0::correctEndianness(m_ManipulatorCoordinateSysZ);
  memcpy(bytes + pos, &m_ManipulatorCoordinateSysZTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_DComponentOfUnitQuaternionQTemp;

  m_DComponentOfUnitQuaternionQTemp = JSIDL_v_1_0::correctEndianness(m_DComponentOfUnitQuaternionQ);
  memcpy(bytes + pos, &m_DComponentOfUnitQuaternionQTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_AComponentOfUnitQuaternionQTemp;

  m_AComponentOfUnitQuaternionQTemp = JSIDL_v_1_0::correctEndianness(m_AComponentOfUnitQuaternionQ);
  memcpy(bytes + pos, &m_AComponentOfUnitQuaternionQTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_BComponentOfUnitQuaternionQTemp;

  m_BComponentOfUnitQuaternionQTemp = JSIDL_v_1_0::correctEndianness(m_BComponentOfUnitQuaternionQ);
  memcpy(bytes + pos, &m_BComponentOfUnitQuaternionQTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_CComponentOfUnitQuaternionQTemp;

  m_CComponentOfUnitQuaternionQTemp = JSIDL_v_1_0::correctEndianness(m_CComponentOfUnitQuaternionQ);
  memcpy(bytes + pos, &m_CComponentOfUnitQuaternionQTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::decode(
    const unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  jUnsignedInteger m_ManipulatorCoordinateSysXTemp;

  memcpy(&m_ManipulatorCoordinateSysXTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_ManipulatorCoordinateSysX = JSIDL_v_1_0::correctEndianness(m_ManipulatorCoordinateSysXTemp);
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_ManipulatorCoordinateSysYTemp;

  memcpy(&m_ManipulatorCoordinateSysYTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_ManipulatorCoordinateSysY = JSIDL_v_1_0::correctEndianness(m_ManipulatorCoordinateSysYTemp);
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_ManipulatorCoordinateSysZTemp;

  memcpy(&m_ManipulatorCoordinateSysZTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_ManipulatorCoordinateSysZ = JSIDL_v_1_0::correctEndianness(m_ManipulatorCoordinateSysZTemp);
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_DComponentOfUnitQuaternionQTemp;

  memcpy(&m_DComponentOfUnitQuaternionQTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_DComponentOfUnitQuaternionQ = JSIDL_v_1_0::correctEndianness(m_DComponentOfUnitQuaternionQTemp);
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_AComponentOfUnitQuaternionQTemp;

  memcpy(&m_AComponentOfUnitQuaternionQTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_AComponentOfUnitQuaternionQ = JSIDL_v_1_0::correctEndianness(m_AComponentOfUnitQuaternionQTemp);
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_BComponentOfUnitQuaternionQTemp;

  memcpy(&m_BComponentOfUnitQuaternionQTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_BComponentOfUnitQuaternionQ = JSIDL_v_1_0::correctEndianness(m_BComponentOfUnitQuaternionQTemp);
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_CComponentOfUnitQuaternionQTemp;

  memcpy(&m_CComponentOfUnitQuaternionQTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_CComponentOfUnitQuaternionQ = JSIDL_v_1_0::correctEndianness(m_CComponentOfUnitQuaternionQTemp);
  pos += sizeof(jUnsignedInteger);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec &ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::operator=(
    const ManipulatorCoordinateSystemRec &value)
{
  m_ManipulatorCoordinateSysX = value.m_ManipulatorCoordinateSysX;
  m_ManipulatorCoordinateSysY = value.m_ManipulatorCoordinateSysY;
  m_ManipulatorCoordinateSysZ = value.m_ManipulatorCoordinateSysZ;
  m_DComponentOfUnitQuaternionQ = value.m_DComponentOfUnitQuaternionQ;
  m_AComponentOfUnitQuaternionQ = value.m_AComponentOfUnitQuaternionQ;
  m_BComponentOfUnitQuaternionQ = value.m_BComponentOfUnitQuaternionQ;
  m_CComponentOfUnitQuaternionQ = value.m_CComponentOfUnitQuaternionQ;

  return *this;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::operator==(
    const ManipulatorCoordinateSystemRec &value) const
{
  if (m_ManipulatorCoordinateSysX != value.m_ManipulatorCoordinateSysX)
  {
    return false;
  }
  if (m_ManipulatorCoordinateSysY != value.m_ManipulatorCoordinateSysY)
  {
    return false;
  }
  if (m_ManipulatorCoordinateSysZ != value.m_ManipulatorCoordinateSysZ)
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

  return true;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::operator!=(
    const ManipulatorCoordinateSystemRec &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::ManipulatorCoordinateSystemRec()
{
  m_parent = NULL;
  m_ManipulatorCoordinateSysX = 0;
  m_ManipulatorCoordinateSysY = 0;
  m_ManipulatorCoordinateSysZ = 0;
  m_DComponentOfUnitQuaternionQ = 0;
  m_AComponentOfUnitQuaternionQ = 0;
  m_BComponentOfUnitQuaternionQ = 0;
  m_CComponentOfUnitQuaternionQ = 0;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::ManipulatorCoordinateSystemRec(
    const ManipulatorCoordinateSystemRec &value)
{
  /// Initiliaze the protected variables
  m_parent = NULL;
  m_ManipulatorCoordinateSysX = 0;
  m_ManipulatorCoordinateSysY = 0;
  m_ManipulatorCoordinateSysZ = 0;
  m_DComponentOfUnitQuaternionQ = 0;
  m_AComponentOfUnitQuaternionQ = 0;
  m_BComponentOfUnitQuaternionQ = 0;
  m_CComponentOfUnitQuaternionQ = 0;

  /// Copy the values
  m_ManipulatorCoordinateSysX = value.m_ManipulatorCoordinateSysX;
  m_ManipulatorCoordinateSysY = value.m_ManipulatorCoordinateSysY;
  m_ManipulatorCoordinateSysZ = value.m_ManipulatorCoordinateSysZ;
  m_DComponentOfUnitQuaternionQ = value.m_DComponentOfUnitQuaternionQ;
  m_AComponentOfUnitQuaternionQ = value.m_AComponentOfUnitQuaternionQ;
  m_BComponentOfUnitQuaternionQ = value.m_BComponentOfUnitQuaternionQ;
  m_CComponentOfUnitQuaternionQ = value.m_CComponentOfUnitQuaternionQ;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec::~ManipulatorCoordinateSystemRec()
{
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::isManipulatorCoordinateSystemRecValid() const
{
  if (checkPresenceVector(0))
  {
    return true;
  }
  return false;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ManipulatorCoordinateSystemRec* const ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::getManipulatorCoordinateSystemRec()
{
  return &m_ManipulatorCoordinateSystemRec;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::setManipulatorCoordinateSystemRec(
    const ManipulatorCoordinateSystemRec &value)
{
  m_ManipulatorCoordinateSystemRec = value;
  setPresenceVector(0);
  setParentPresenceVector();
  return 0;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::setParent(
    ReportManipulatorSpecification* parent)
{
  m_parent = parent;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::setParentPresenceVector()
{
  if (m_parent != NULL)
  {
    m_parent->setParentPresenceVector();
  }
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::setParent(
    FirstJointParameters* parent)
{
  m_parent = parent;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::setParentPresenceVector()
{
  if (m_parent != NULL)
  {
    m_parent->setParentPresenceVector();
  }
}

jUnsignedByte ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::getPresenceVector()
{
  return m_PresenceVector;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::setPresenceVector(
    unsigned int index)
{
  std::bitset < sizeof(jUnsignedByte) * 8 > pvBitSet((int)(m_PresenceVector));

  pvBitSet[index] = 1;
  m_PresenceVector = (jUnsignedByte)pvBitSet.to_ulong();
  return 0;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::checkPresenceVector(
    unsigned int index) const
{
  std::bitset < sizeof(jUnsignedByte) * 8 > pvBitSet((int)(m_PresenceVector));

  return (pvBitSet[index] == 1);
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::getJoint1Offset()
{
  double value;

  double scaleFactor = (10.0 - -10.0) / 65535.0;
  double bias = -10.0;

  value = m_Joint1Offset * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::setJoint1Offset(
    double value)
{
  if ((value >= -10.0) && (value <= 10.0))
  {
    double scaleFactor = (10.0 - -10.0) / 65535.0;
    double bias = -10.0;

    m_Joint1Offset = (jUnsignedShortInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::isJoint1MinValueValid() const
{
  if (checkPresenceVector(0))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::getJoint1MinValue()
{
  double value;

  double scaleFactor = (25.13274122871834590768 - -25.13274122871834590768) / 4.294967295E9;
  double bias = -25.13274122871834590768;

  value = m_Joint1MinValue * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::setJoint1MinValue(
    double value)
{
  if ((value >= -25.13274122871834590768) && (value <= 25.13274122871834590768))
  {
    double scaleFactor = (25.13274122871834590768 - -25.13274122871834590768) / 4.294967295E9;
    double bias = -25.13274122871834590768;

    m_Joint1MinValue = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(0);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::isJoint1MaxValueValid() const
{
  if (checkPresenceVector(1))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::getJoint1MaxValue()
{
  double value;

  double scaleFactor = (25.13274122871834590768 - -25.13274122871834590768) / 4.294967295E9;
  double bias = -25.13274122871834590768;

  value = m_Joint1MaxValue * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::setJoint1MaxValue(
    double value)
{
  if ((value >= -25.13274122871834590768) && (value <= 25.13274122871834590768))
  {
    double scaleFactor = (25.13274122871834590768 - -25.13274122871834590768) / 4.294967295E9;
    double bias = -25.13274122871834590768;

    m_Joint1MaxValue = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(1);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::isJoint1MaxSpeedValid() const
{
  if (checkPresenceVector(2))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::getJoint1MaxSpeed()
{
  double value;

  double scaleFactor = (31.4159265358979323846 - 0.0) / 4.294967295E9;
  double bias = 0.0;

  value = m_Joint1MaxSpeed * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::setJoint1MaxSpeed(
    double value)
{
  if ((value >= 0.0) && (value <= 31.4159265358979323846))
  {
    double scaleFactor = (31.4159265358979323846 - 0.0) / 4.294967295E9;
    double bias = 0.0;

    m_Joint1MaxSpeed = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(2);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::isJoint1MaxTorqueValid() const
{
  if (checkPresenceVector(3))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::getJoint1MaxTorque()
{
  double value;

  double scaleFactor = (5000.0 - 0.0) / 4.294967295E9;
  double bias = 0.0;

  value = m_Joint1MaxTorque * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::setJoint1MaxTorque(
    double value)
{
  if ((value >= 0.0) && (value <= 5000.0))
  {
    double scaleFactor = (5000.0 - 0.0) / 4.294967295E9;
    double bias = 0.0;

    m_Joint1MaxTorque = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(3);
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
const unsigned int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::getSize()
{
  unsigned int size = 0;

  size += sizeof(jUnsignedByte);
  size += sizeof(jUnsignedShortInteger);
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

  return size;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::encode(
    unsigned char *bytes)
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
  jUnsignedShortInteger m_Joint1OffsetTemp;

  m_Joint1OffsetTemp = JSIDL_v_1_0::correctEndianness(m_Joint1Offset);
  memcpy(bytes + pos, &m_Joint1OffsetTemp, sizeof(jUnsignedShortInteger));
  pos += sizeof(jUnsignedShortInteger);
  if (checkPresenceVector(0))
  {
    jUnsignedInteger m_Joint1MinValueTemp;

    m_Joint1MinValueTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MinValue);
    memcpy(bytes + pos, &m_Joint1MinValueTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(1))
  {
    jUnsignedInteger m_Joint1MaxValueTemp;

    m_Joint1MaxValueTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxValue);
    memcpy(bytes + pos, &m_Joint1MaxValueTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(2))
  {
    jUnsignedInteger m_Joint1MaxSpeedTemp;

    m_Joint1MaxSpeedTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxSpeed);
    memcpy(bytes + pos, &m_Joint1MaxSpeedTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(3))
  {
    jUnsignedInteger m_Joint1MaxTorqueTemp;

    m_Joint1MaxTorqueTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxTorque);
    memcpy(bytes + pos, &m_Joint1MaxTorqueTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::decode(
    const unsigned char *bytes)
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
  jUnsignedShortInteger m_Joint1OffsetTemp;

  memcpy(&m_Joint1OffsetTemp, bytes + pos, sizeof(jUnsignedShortInteger));
  m_Joint1Offset = JSIDL_v_1_0::correctEndianness(m_Joint1OffsetTemp);
  pos += sizeof(jUnsignedShortInteger);
  if (checkPresenceVector(0))
  {
    jUnsignedInteger m_Joint1MinValueTemp;

    memcpy(&m_Joint1MinValueTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_Joint1MinValue = JSIDL_v_1_0::correctEndianness(m_Joint1MinValueTemp);
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(1))
  {
    jUnsignedInteger m_Joint1MaxValueTemp;

    memcpy(&m_Joint1MaxValueTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_Joint1MaxValue = JSIDL_v_1_0::correctEndianness(m_Joint1MaxValueTemp);
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(2))
  {
    jUnsignedInteger m_Joint1MaxSpeedTemp;

    memcpy(&m_Joint1MaxSpeedTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_Joint1MaxSpeed = JSIDL_v_1_0::correctEndianness(m_Joint1MaxSpeedTemp);
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(3))
  {
    jUnsignedInteger m_Joint1MaxTorqueTemp;

    memcpy(&m_Joint1MaxTorqueTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_Joint1MaxTorque = JSIDL_v_1_0::correctEndianness(m_Joint1MaxTorqueTemp);
    pos += sizeof(jUnsignedInteger);
  }
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec &ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::operator=(
    const RevoluteJoint1OffsetRec &value)
{
  m_PresenceVector = value.m_PresenceVector;
  m_Joint1Offset = value.m_Joint1Offset;
  m_Joint1MinValue = value.m_Joint1MinValue;
  m_Joint1MaxValue = value.m_Joint1MaxValue;
  m_Joint1MaxSpeed = value.m_Joint1MaxSpeed;
  m_Joint1MaxTorque = value.m_Joint1MaxTorque;

  return *this;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::operator==(
    const RevoluteJoint1OffsetRec &value) const
{
  if (m_PresenceVector != value.m_PresenceVector)
  {
    return false;
  }
  if (m_Joint1Offset != value.m_Joint1Offset)
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
  if (m_Joint1MaxTorque != value.m_Joint1MaxTorque)
  {
    return false;
  }

  return true;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::operator!=(
    const RevoluteJoint1OffsetRec &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::RevoluteJoint1OffsetRec()
{
  m_parent = NULL;
  m_PresenceVector = 0;
  m_Joint1Offset = 0;
  m_Joint1MinValue = 0;
  m_Joint1MaxValue = 0;
  m_Joint1MaxSpeed = 0;
  m_Joint1MaxTorque = 0;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::RevoluteJoint1OffsetRec(
    const RevoluteJoint1OffsetRec &value)
{
  /// Initiliaze the protected variables
  m_parent = NULL;
  m_PresenceVector = 0;
  m_Joint1Offset = 0;
  m_Joint1MinValue = 0;
  m_Joint1MaxValue = 0;
  m_Joint1MaxSpeed = 0;
  m_Joint1MaxTorque = 0;

  /// Copy the values
  m_PresenceVector = value.m_PresenceVector;
  m_Joint1Offset = value.m_Joint1Offset;
  m_Joint1MinValue = value.m_Joint1MinValue;
  m_Joint1MaxValue = value.m_Joint1MaxValue;
  m_Joint1MaxSpeed = value.m_Joint1MaxSpeed;
  m_Joint1MaxTorque = value.m_Joint1MaxTorque;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec::~RevoluteJoint1OffsetRec()
{
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::RevoluteJoint1OffsetRec* const ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::getRevoluteJoint1OffsetRec()
{
  return &m_RevoluteJoint1OffsetRec;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::setRevoluteJoint1OffsetRec(
    const RevoluteJoint1OffsetRec &value)
{
  m_RevoluteJoint1OffsetRec = value;
  setParentPresenceVector();
  return 0;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::setParent(
    FirstJointParameters* parent)
{
  m_parent = parent;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::setParentPresenceVector()
{
  if (m_parent != NULL)
  {
    m_parent->setParentPresenceVector();
  }
}

jUnsignedByte ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::getPresenceVector()
{
  return m_PresenceVector;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::setPresenceVector(
    unsigned int index)
{
  std::bitset < sizeof(jUnsignedByte) * 8 > pvBitSet((int)(m_PresenceVector));

  pvBitSet[index] = 1;
  m_PresenceVector = (jUnsignedByte)pvBitSet.to_ulong();
  return 0;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::checkPresenceVector(
    unsigned int index) const
{
  std::bitset < sizeof(jUnsignedByte) * 8 > pvBitSet((int)(m_PresenceVector));

  return (pvBitSet[index] == 1);
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::getJoint1Angle()
{
  double value;

  double scaleFactor = (3.14159265358979323846 - -3.14159265358979323846) / 65535.0;
  double bias = -3.14159265358979323846;

  value = m_Joint1Angle * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::setJoint1Angle(
    double value)
{
  if ((value >= -3.14159265358979323846) && (value <= 3.14159265358979323846))
  {
    double scaleFactor = (3.14159265358979323846 - -3.14159265358979323846) / 65535.0;
    double bias = -3.14159265358979323846;

    m_Joint1Angle = (jUnsignedShortInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::getJoint1MinValue()
{
  double value;

  double scaleFactor = (10.0 - -10.0) / 4.294967295E9;
  double bias = -10.0;

  value = m_Joint1MinValue * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::setJoint1MinValue(
    double value)
{
  if ((value >= -10.0) && (value <= 10.0))
  {
    double scaleFactor = (10.0 - -10.0) / 4.294967295E9;
    double bias = -10.0;

    m_Joint1MinValue = (jUnsignedInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::getJoint1MaxValue()
{
  double value;

  double scaleFactor = (10.0 - -10.0) / 4.294967295E9;
  double bias = -10.0;

  value = m_Joint1MaxValue * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::setJoint1MaxValue(
    double value)
{
  if ((value >= -10.0) && (value <= 10.0))
  {
    double scaleFactor = (10.0 - -10.0) / 4.294967295E9;
    double bias = -10.0;

    m_Joint1MaxValue = (jUnsignedInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::isJoint1MaxSpeedValid() const
{
  if (checkPresenceVector(0))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::getJoint1MaxSpeed()
{
  double value;

  double scaleFactor = (5.0 - -5.0) / 4.294967295E9;
  double bias = -5.0;

  value = m_Joint1MaxSpeed * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::setJoint1MaxSpeed(
    double value)
{
  if ((value >= -5.0) && (value <= 5.0))
  {
    double scaleFactor = (5.0 - -5.0) / 4.294967295E9;
    double bias = -5.0;

    m_Joint1MaxSpeed = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(0);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::isJoint1MaxForceValid() const
{
  if (checkPresenceVector(1))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::getJoint1MaxForce()
{
  double value;

  double scaleFactor = (5000.0 - 0.0) / 4.294967295E9;
  double bias = 0.0;

  value = m_Joint1MaxForce * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::setJoint1MaxForce(
    double value)
{
  if ((value >= 0.0) && (value <= 5000.0))
  {
    double scaleFactor = (5000.0 - 0.0) / 4.294967295E9;
    double bias = 0.0;

    m_Joint1MaxForce = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(1);
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
const unsigned int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::getSize()
{
  unsigned int size = 0;

  size += sizeof(jUnsignedByte);
  size += sizeof(jUnsignedShortInteger);
  size += sizeof(jUnsignedInteger);
  size += sizeof(jUnsignedInteger);
  if (checkPresenceVector(0))
  {
    size += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(1))
  {
    size += sizeof(jUnsignedInteger);
  }

  return size;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::encode(
    unsigned char *bytes)
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
  jUnsignedShortInteger m_Joint1AngleTemp;

  m_Joint1AngleTemp = JSIDL_v_1_0::correctEndianness(m_Joint1Angle);
  memcpy(bytes + pos, &m_Joint1AngleTemp, sizeof(jUnsignedShortInteger));
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedInteger m_Joint1MinValueTemp;

  m_Joint1MinValueTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MinValue);
  memcpy(bytes + pos, &m_Joint1MinValueTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_Joint1MaxValueTemp;

  m_Joint1MaxValueTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxValue);
  memcpy(bytes + pos, &m_Joint1MaxValueTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
  if (checkPresenceVector(0))
  {
    jUnsignedInteger m_Joint1MaxSpeedTemp;

    m_Joint1MaxSpeedTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxSpeed);
    memcpy(bytes + pos, &m_Joint1MaxSpeedTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(1))
  {
    jUnsignedInteger m_Joint1MaxForceTemp;

    m_Joint1MaxForceTemp = JSIDL_v_1_0::correctEndianness(m_Joint1MaxForce);
    memcpy(bytes + pos, &m_Joint1MaxForceTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::decode(
    const unsigned char *bytes)
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
  jUnsignedShortInteger m_Joint1AngleTemp;

  memcpy(&m_Joint1AngleTemp, bytes + pos, sizeof(jUnsignedShortInteger));
  m_Joint1Angle = JSIDL_v_1_0::correctEndianness(m_Joint1AngleTemp);
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedInteger m_Joint1MinValueTemp;

  memcpy(&m_Joint1MinValueTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_Joint1MinValue = JSIDL_v_1_0::correctEndianness(m_Joint1MinValueTemp);
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_Joint1MaxValueTemp;

  memcpy(&m_Joint1MaxValueTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_Joint1MaxValue = JSIDL_v_1_0::correctEndianness(m_Joint1MaxValueTemp);
  pos += sizeof(jUnsignedInteger);
  if (checkPresenceVector(0))
  {
    jUnsignedInteger m_Joint1MaxSpeedTemp;

    memcpy(&m_Joint1MaxSpeedTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_Joint1MaxSpeed = JSIDL_v_1_0::correctEndianness(m_Joint1MaxSpeedTemp);
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(1))
  {
    jUnsignedInteger m_Joint1MaxForceTemp;

    memcpy(&m_Joint1MaxForceTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_Joint1MaxForce = JSIDL_v_1_0::correctEndianness(m_Joint1MaxForceTemp);
    pos += sizeof(jUnsignedInteger);
  }
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec &ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::operator=(
    const PrismaticJoint1AngleRec &value)
{
  m_PresenceVector = value.m_PresenceVector;
  m_Joint1Angle = value.m_Joint1Angle;
  m_Joint1MinValue = value.m_Joint1MinValue;
  m_Joint1MaxValue = value.m_Joint1MaxValue;
  m_Joint1MaxSpeed = value.m_Joint1MaxSpeed;
  m_Joint1MaxForce = value.m_Joint1MaxForce;

  return *this;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::operator==(
    const PrismaticJoint1AngleRec &value) const
{
  if (m_PresenceVector != value.m_PresenceVector)
  {
    return false;
  }
  if (m_Joint1Angle != value.m_Joint1Angle)
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
  if (m_Joint1MaxForce != value.m_Joint1MaxForce)
  {
    return false;
  }

  return true;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::operator!=(
    const PrismaticJoint1AngleRec &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::PrismaticJoint1AngleRec()
{
  m_parent = NULL;
  m_PresenceVector = 0;
  m_Joint1Angle = 0;
  m_Joint1MinValue = 0;
  m_Joint1MaxValue = 0;
  m_Joint1MaxSpeed = 0;
  m_Joint1MaxForce = 0;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::PrismaticJoint1AngleRec(
    const PrismaticJoint1AngleRec &value)
{
  /// Initiliaze the protected variables
  m_parent = NULL;
  m_PresenceVector = 0;
  m_Joint1Angle = 0;
  m_Joint1MinValue = 0;
  m_Joint1MaxValue = 0;
  m_Joint1MaxSpeed = 0;
  m_Joint1MaxForce = 0;

  /// Copy the values
  m_PresenceVector = value.m_PresenceVector;
  m_Joint1Angle = value.m_Joint1Angle;
  m_Joint1MinValue = value.m_Joint1MinValue;
  m_Joint1MaxValue = value.m_Joint1MaxValue;
  m_Joint1MaxSpeed = value.m_Joint1MaxSpeed;
  m_Joint1MaxForce = value.m_Joint1MaxForce;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec::~PrismaticJoint1AngleRec()
{
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::PrismaticJoint1AngleRec* const ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::getPrismaticJoint1AngleRec()
{
  return &m_PrismaticJoint1AngleRec;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::setPrismaticJoint1AngleRec(
    const PrismaticJoint1AngleRec &value)
{
  m_PrismaticJoint1AngleRec = value;
  setParentPresenceVector();
  return 0;
}

jUnsignedByte ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::getFieldValue() const
{
  return m_FieldValue;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::setFieldValue(
    jUnsignedByte fieldValue)
{
  if (fieldValue > 1)
  {
    return 1;
  }

  m_FieldValue = fieldValue;
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
const unsigned int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::getSize()
{
  unsigned int size = 0;

  size += sizeof(jUnsignedByte);

  switch (m_FieldValue)
  {
    case 0:
      size += m_RevoluteJoint1OffsetRec.getSize();
      break;
    case 1:
      size += m_PrismaticJoint1AngleRec.getSize();
      break;
  }

  return size;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::encode(
    unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  jUnsignedByte m_FieldValueTemp;

  m_FieldValueTemp = JSIDL_v_1_0::correctEndianness(m_FieldValue);
  memcpy(bytes + pos, &m_FieldValueTemp, sizeof(jUnsignedByte));
  pos += sizeof(jUnsignedByte);

  switch (m_FieldValue)
  {
    case 0:
      m_RevoluteJoint1OffsetRec.encode(bytes + pos);
      pos += m_RevoluteJoint1OffsetRec.getSize();
      break;
    case 1:
      m_PrismaticJoint1AngleRec.encode(bytes + pos);
      pos += m_PrismaticJoint1AngleRec.getSize();
      break;
  }
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::decode(
    const unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  jUnsignedByte m_FieldValueTemp;

  memcpy(&m_FieldValueTemp, bytes + pos, sizeof(jUnsignedByte));
  m_FieldValue = JSIDL_v_1_0::correctEndianness(m_FieldValueTemp);
  pos += sizeof(jUnsignedByte);

  switch (m_FieldValue)
  {
    case 0:
      m_RevoluteJoint1OffsetRec.decode(bytes + pos);
      pos += m_RevoluteJoint1OffsetRec.getSize();
      break;
    case 1:
      m_PrismaticJoint1AngleRec.decode(bytes + pos);
      pos += m_PrismaticJoint1AngleRec.getSize();
      break;
  }
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters &ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::operator=(
    const FirstJointParameters &value)
{
  m_FieldValue = value.m_FieldValue;
  m_RevoluteJoint1OffsetRec = value.m_RevoluteJoint1OffsetRec;
  m_RevoluteJoint1OffsetRec.setParent(this);
  m_PrismaticJoint1AngleRec = value.m_PrismaticJoint1AngleRec;
  m_PrismaticJoint1AngleRec.setParent(this);

  return *this;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::operator==(
    const FirstJointParameters &value) const
{
  if (m_FieldValue != value.m_FieldValue)
  {
    return false;
  }
  if (m_RevoluteJoint1OffsetRec != value.m_RevoluteJoint1OffsetRec)
  {
    return false;
  }
  if (m_PrismaticJoint1AngleRec != value.m_PrismaticJoint1AngleRec)
  {
    return false;
  }

  return true;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::operator!=(
    const FirstJointParameters &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::FirstJointParameters()
{
  m_parent = NULL;
  m_FieldValue = 0;
  m_RevoluteJoint1OffsetRec.setParent(this);
  /// No Initialization of m_RevoluteJoint1OffsetRec necessary.
  m_PrismaticJoint1AngleRec.setParent(this);
  /// No Initialization of m_PrismaticJoint1AngleRec necessary.
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::FirstJointParameters(
    const FirstJointParameters &value)
{
  /// Initiliaze the protected variables
  m_parent = NULL;
  m_FieldValue = 0;
  m_RevoluteJoint1OffsetRec.setParent(this);
  /// No Initialization of m_RevoluteJoint1OffsetRec necessary.
  m_PrismaticJoint1AngleRec.setParent(this);
  /// No Initialization of m_PrismaticJoint1AngleRec necessary.

  /// Copy the values
  m_FieldValue = value.m_FieldValue;
  m_RevoluteJoint1OffsetRec = value.m_RevoluteJoint1OffsetRec;
  m_RevoluteJoint1OffsetRec.setParent(this);
  m_PrismaticJoint1AngleRec = value.m_PrismaticJoint1AngleRec;
  m_PrismaticJoint1AngleRec.setParent(this);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters::~FirstJointParameters()
{
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::FirstJointParameters* const ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::getFirstJointParameters()
{
  return &m_FirstJointParameters;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::setFirstJointParameters(
    const FirstJointParameters &value)
{
  m_FirstJointParameters = value;
  setParentPresenceVector();
  return 0;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::setParent(
    ReportManipulatorSpecification* parent)
{
  m_parent = parent;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::setParentPresenceVector()
{
  if (m_parent != NULL)
  {
    m_parent->setParentPresenceVector();
  }
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::setParent(
    JointSpecificationList* parent)
{
  m_parent = parent;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::setParentPresenceVector()
{
  if (m_parent != NULL)
  {
    m_parent->setParentPresenceVector();
  }
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::setParent(
    JointSpecifications* parent)
{
  m_parent = parent;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::setParentPresenceVector()
{
  if (m_parent != NULL)
  {
    m_parent->setParentPresenceVector();
  }
}

jUnsignedByte ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::getPresenceVector()
{
  return m_PresenceVector;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::setPresenceVector(
    unsigned int index)
{
  std::bitset < sizeof(jUnsignedByte) * 8 > pvBitSet((int)(m_PresenceVector));

  pvBitSet[index] = 1;
  m_PresenceVector = (jUnsignedByte)pvBitSet.to_ulong();
  return 0;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::checkPresenceVector(
    unsigned int index) const
{
  std::bitset < sizeof(jUnsignedByte) * 8 > pvBitSet((int)(m_PresenceVector));

  return (pvBitSet[index] == 1);
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::getLinkLength()
{
  double value;

  double scaleFactor = (10.0 - -10.0) / 65535.0;
  double bias = -10.0;

  value = m_LinkLength * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::setLinkLength(
    double value)
{
  if ((value >= -10.0) && (value <= 10.0))
  {
    double scaleFactor = (10.0 - -10.0) / 65535.0;
    double bias = -10.0;

    m_LinkLength = (jUnsignedShortInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::getTwistAngle()
{
  double value;

  double scaleFactor = (3.14159265358979323846 - -3.14159265358979323846) / 65535.0;
  double bias = -3.14159265358979323846;

  value = m_TwistAngle * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::setTwistAngle(
    double value)
{
  if ((value >= -3.14159265358979323846) && (value <= 3.14159265358979323846))
  {
    double scaleFactor = (3.14159265358979323846 - -3.14159265358979323846) / 65535.0;
    double bias = -3.14159265358979323846;

    m_TwistAngle = (jUnsignedShortInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::getJointOffset()
{
  double value;

  double scaleFactor = (10.0 - -10.0) / 65535.0;
  double bias = -10.0;

  value = m_JointOffset * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::setJointOffset(
    double value)
{
  if ((value >= -10.0) && (value <= 10.0))
  {
    double scaleFactor = (10.0 - -10.0) / 65535.0;
    double bias = -10.0;

    m_JointOffset = (jUnsignedShortInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::isMinValueValid() const
{
  if (checkPresenceVector(0))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::getMinValue()
{
  double value;

  double scaleFactor = (25.13274122871834590768 - -25.13274122871834590768) / 4.294967295E9;
  double bias = -25.13274122871834590768;

  value = m_MinValue * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::setMinValue(
    double value)
{
  if ((value >= -25.13274122871834590768) && (value <= 25.13274122871834590768))
  {
    double scaleFactor = (25.13274122871834590768 - -25.13274122871834590768) / 4.294967295E9;
    double bias = -25.13274122871834590768;

    m_MinValue = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(0);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::isMaxValueValid() const
{
  if (checkPresenceVector(1))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::getMaxValue()
{
  double value;

  double scaleFactor = (25.13274122871834590768 - -25.13274122871834590768) / 4.294967295E9;
  double bias = -25.13274122871834590768;

  value = m_MaxValue * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::setMaxValue(
    double value)
{
  if ((value >= -25.13274122871834590768) && (value <= 25.13274122871834590768))
  {
    double scaleFactor = (25.13274122871834590768 - -25.13274122871834590768) / 4.294967295E9;
    double bias = -25.13274122871834590768;

    m_MaxValue = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(1);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::isMaxSpeedValid() const
{
  if (checkPresenceVector(2))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::getMaxSpeed()
{
  double value;

  double scaleFactor = (31.4159265358979323846 - 0.0) / 4.294967295E9;
  double bias = 0.0;

  value = m_MaxSpeed * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::setMaxSpeed(
    double value)
{
  if ((value >= 0.0) && (value <= 31.4159265358979323846))
  {
    double scaleFactor = (31.4159265358979323846 - 0.0) / 4.294967295E9;
    double bias = 0.0;

    m_MaxSpeed = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(2);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::isMaxTorqueValid() const
{
  if (checkPresenceVector(3))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::getMaxTorque()
{
  double value;

  double scaleFactor = (5000.0 - 0.0) / 4.294967295E9;
  double bias = 0.0;

  value = m_MaxTorque * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::setMaxTorque(
    double value)
{
  if ((value >= 0.0) && (value <= 5000.0))
  {
    double scaleFactor = (5000.0 - 0.0) / 4.294967295E9;
    double bias = 0.0;

    m_MaxTorque = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(3);
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
const unsigned int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::getSize()
{
  unsigned int size = 0;

  size += sizeof(jUnsignedByte);
  size += sizeof(jUnsignedShortInteger);
  size += sizeof(jUnsignedShortInteger);
  size += sizeof(jUnsignedShortInteger);
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

  return size;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::encode(
    unsigned char *bytes)
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
  jUnsignedShortInteger m_LinkLengthTemp;

  m_LinkLengthTemp = JSIDL_v_1_0::correctEndianness(m_LinkLength);
  memcpy(bytes + pos, &m_LinkLengthTemp, sizeof(jUnsignedShortInteger));
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedShortInteger m_TwistAngleTemp;

  m_TwistAngleTemp = JSIDL_v_1_0::correctEndianness(m_TwistAngle);
  memcpy(bytes + pos, &m_TwistAngleTemp, sizeof(jUnsignedShortInteger));
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedShortInteger m_JointOffsetTemp;

  m_JointOffsetTemp = JSIDL_v_1_0::correctEndianness(m_JointOffset);
  memcpy(bytes + pos, &m_JointOffsetTemp, sizeof(jUnsignedShortInteger));
  pos += sizeof(jUnsignedShortInteger);
  if (checkPresenceVector(0))
  {
    jUnsignedInteger m_MinValueTemp;

    m_MinValueTemp = JSIDL_v_1_0::correctEndianness(m_MinValue);
    memcpy(bytes + pos, &m_MinValueTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(1))
  {
    jUnsignedInteger m_MaxValueTemp;

    m_MaxValueTemp = JSIDL_v_1_0::correctEndianness(m_MaxValue);
    memcpy(bytes + pos, &m_MaxValueTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(2))
  {
    jUnsignedInteger m_MaxSpeedTemp;

    m_MaxSpeedTemp = JSIDL_v_1_0::correctEndianness(m_MaxSpeed);
    memcpy(bytes + pos, &m_MaxSpeedTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(3))
  {
    jUnsignedInteger m_MaxTorqueTemp;

    m_MaxTorqueTemp = JSIDL_v_1_0::correctEndianness(m_MaxTorque);
    memcpy(bytes + pos, &m_MaxTorqueTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::decode(
    const unsigned char *bytes)
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
  jUnsignedShortInteger m_LinkLengthTemp;

  memcpy(&m_LinkLengthTemp, bytes + pos, sizeof(jUnsignedShortInteger));
  m_LinkLength = JSIDL_v_1_0::correctEndianness(m_LinkLengthTemp);
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedShortInteger m_TwistAngleTemp;

  memcpy(&m_TwistAngleTemp, bytes + pos, sizeof(jUnsignedShortInteger));
  m_TwistAngle = JSIDL_v_1_0::correctEndianness(m_TwistAngleTemp);
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedShortInteger m_JointOffsetTemp;

  memcpy(&m_JointOffsetTemp, bytes + pos, sizeof(jUnsignedShortInteger));
  m_JointOffset = JSIDL_v_1_0::correctEndianness(m_JointOffsetTemp);
  pos += sizeof(jUnsignedShortInteger);
  if (checkPresenceVector(0))
  {
    jUnsignedInteger m_MinValueTemp;

    memcpy(&m_MinValueTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_MinValue = JSIDL_v_1_0::correctEndianness(m_MinValueTemp);
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(1))
  {
    jUnsignedInteger m_MaxValueTemp;

    memcpy(&m_MaxValueTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_MaxValue = JSIDL_v_1_0::correctEndianness(m_MaxValueTemp);
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(2))
  {
    jUnsignedInteger m_MaxSpeedTemp;

    memcpy(&m_MaxSpeedTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_MaxSpeed = JSIDL_v_1_0::correctEndianness(m_MaxSpeedTemp);
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(3))
  {
    jUnsignedInteger m_MaxTorqueTemp;

    memcpy(&m_MaxTorqueTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_MaxTorque = JSIDL_v_1_0::correctEndianness(m_MaxTorqueTemp);
    pos += sizeof(jUnsignedInteger);
  }
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec &ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::operator=(
    const RevoluteJointSpecificationRec &value)
{
  m_PresenceVector = value.m_PresenceVector;
  m_LinkLength = value.m_LinkLength;
  m_TwistAngle = value.m_TwistAngle;
  m_JointOffset = value.m_JointOffset;
  m_MinValue = value.m_MinValue;
  m_MaxValue = value.m_MaxValue;
  m_MaxSpeed = value.m_MaxSpeed;
  m_MaxTorque = value.m_MaxTorque;

  return *this;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::operator==(
    const RevoluteJointSpecificationRec &value) const
{
  if (m_PresenceVector != value.m_PresenceVector)
  {
    return false;
  }
  if (m_LinkLength != value.m_LinkLength)
  {
    return false;
  }
  if (m_TwistAngle != value.m_TwistAngle)
  {
    return false;
  }
  if (m_JointOffset != value.m_JointOffset)
  {
    return false;
  }
  if (m_MinValue != value.m_MinValue)
  {
    return false;
  }
  if (m_MaxValue != value.m_MaxValue)
  {
    return false;
  }
  if (m_MaxSpeed != value.m_MaxSpeed)
  {
    return false;
  }
  if (m_MaxTorque != value.m_MaxTorque)
  {
    return false;
  }

  return true;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::operator!=(
    const RevoluteJointSpecificationRec &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::RevoluteJointSpecificationRec()
{
  m_parent = NULL;
  m_PresenceVector = 0;
  m_LinkLength = 0;
  m_TwistAngle = 0;
  m_JointOffset = 0;
  m_MinValue = 0;
  m_MaxValue = 0;
  m_MaxSpeed = 0;
  m_MaxTorque = 0;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::RevoluteJointSpecificationRec(
    const RevoluteJointSpecificationRec &value)
{
  /// Initiliaze the protected variables
  m_parent = NULL;
  m_PresenceVector = 0;
  m_LinkLength = 0;
  m_TwistAngle = 0;
  m_JointOffset = 0;
  m_MinValue = 0;
  m_MaxValue = 0;
  m_MaxSpeed = 0;
  m_MaxTorque = 0;

  /// Copy the values
  m_PresenceVector = value.m_PresenceVector;
  m_LinkLength = value.m_LinkLength;
  m_TwistAngle = value.m_TwistAngle;
  m_JointOffset = value.m_JointOffset;
  m_MinValue = value.m_MinValue;
  m_MaxValue = value.m_MaxValue;
  m_MaxSpeed = value.m_MaxSpeed;
  m_MaxTorque = value.m_MaxTorque;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec::~RevoluteJointSpecificationRec()
{
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::RevoluteJointSpecificationRec* const ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::getRevoluteJointSpecificationRec()
{
  return &m_RevoluteJointSpecificationRec;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::setRevoluteJointSpecificationRec(
    const RevoluteJointSpecificationRec &value)
{
  m_RevoluteJointSpecificationRec = value;
  setParentPresenceVector();
  return 0;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::setParent(
    JointSpecifications* parent)
{
  m_parent = parent;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::setParentPresenceVector()
{
  if (m_parent != NULL)
  {
    m_parent->setParentPresenceVector();
  }
}

jUnsignedByte ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::getPresenceVector()
{
  return m_PresenceVector;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::setPresenceVector(
    unsigned int index)
{
  std::bitset < sizeof(jUnsignedByte) * 8 > pvBitSet((int)(m_PresenceVector));

  pvBitSet[index] = 1;
  m_PresenceVector = (jUnsignedByte)pvBitSet.to_ulong();
  return 0;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::checkPresenceVector(
    unsigned int index) const
{
  std::bitset < sizeof(jUnsignedByte) * 8 > pvBitSet((int)(m_PresenceVector));

  return (pvBitSet[index] == 1);
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::getLinkLength()
{
  double value;

  double scaleFactor = (10.0 - -10.0) / 65535.0;
  double bias = -10.0;

  value = m_LinkLength * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::setLinkLength(
    double value)
{
  if ((value >= -10.0) && (value <= 10.0))
  {
    double scaleFactor = (10.0 - -10.0) / 65535.0;
    double bias = -10.0;

    m_LinkLength = (jUnsignedShortInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::getTwistAngle()
{
  double value;

  double scaleFactor = (3.14159265358979323846 - -3.14159265358979323846) / 65535.0;
  double bias = -3.14159265358979323846;

  value = m_TwistAngle * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::setTwistAngle(
    double value)
{
  if ((value >= -3.14159265358979323846) && (value <= 3.14159265358979323846))
  {
    double scaleFactor = (3.14159265358979323846 - -3.14159265358979323846) / 65535.0;
    double bias = -3.14159265358979323846;

    m_TwistAngle = (jUnsignedShortInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::getJointAngle()
{
  double value;

  double scaleFactor = (3.14159265358979323846 - -3.14159265358979323846) / 65535.0;
  double bias = -3.14159265358979323846;

  value = m_JointAngle * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::setJointAngle(
    double value)
{
  if ((value >= -3.14159265358979323846) && (value <= 3.14159265358979323846))
  {
    double scaleFactor = (3.14159265358979323846 - -3.14159265358979323846) / 65535.0;
    double bias = -3.14159265358979323846;

    m_JointAngle = (jUnsignedShortInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::getMinValue()
{
  double value;

  double scaleFactor = (10.0 - -10.0) / 4.294967295E9;
  double bias = -10.0;

  value = m_MinValue * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::setMinValue(
    double value)
{
  if ((value >= -10.0) && (value <= 10.0))
  {
    double scaleFactor = (10.0 - -10.0) / 4.294967295E9;
    double bias = -10.0;

    m_MinValue = (jUnsignedInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::getMaxValue()
{
  double value;

  double scaleFactor = (10.0 - -10.0) / 4.294967295E9;
  double bias = -10.0;

  value = m_MaxValue * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::setMaxValue(
    double value)
{
  if ((value >= -10.0) && (value <= 10.0))
  {
    double scaleFactor = (10.0 - -10.0) / 4.294967295E9;
    double bias = -10.0;

    m_MaxValue = (jUnsignedInteger)((value - bias) / scaleFactor);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::isMaxSpeedValid() const
{
  if (checkPresenceVector(0))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::getMaxSpeed()
{
  double value;

  double scaleFactor = (5.0 - -5.0) / 4.294967295E9;
  double bias = -5.0;

  value = m_MaxSpeed * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::setMaxSpeed(
    double value)
{
  if ((value >= -5.0) && (value <= 5.0))
  {
    double scaleFactor = (5.0 - -5.0) / 4.294967295E9;
    double bias = -5.0;

    m_MaxSpeed = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(0);
    setParentPresenceVector();
    return 0;
  }
  return 1;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::isMaxForceValid() const
{
  if (checkPresenceVector(1))
  {
    return true;
  }
  return false;
}

double ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::getMaxForce()
{
  double value;

  double scaleFactor = (5000.0 - 0.0) / 4.294967295E9;
  double bias = 0.0;

  value = m_MaxForce * scaleFactor + bias;

  return value;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::setMaxForce(
    double value)
{
  if ((value >= 0.0) && (value <= 5000.0))
  {
    double scaleFactor = (5000.0 - 0.0) / 4.294967295E9;
    double bias = 0.0;

    m_MaxForce = (jUnsignedInteger)((value - bias) / scaleFactor);
    setPresenceVector(1);
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
const unsigned int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::getSize()
{
  unsigned int size = 0;

  size += sizeof(jUnsignedByte);
  size += sizeof(jUnsignedShortInteger);
  size += sizeof(jUnsignedShortInteger);
  size += sizeof(jUnsignedShortInteger);
  size += sizeof(jUnsignedInteger);
  size += sizeof(jUnsignedInteger);
  if (checkPresenceVector(0))
  {
    size += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(1))
  {
    size += sizeof(jUnsignedInteger);
  }

  return size;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::encode(
    unsigned char *bytes)
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
  jUnsignedShortInteger m_LinkLengthTemp;

  m_LinkLengthTemp = JSIDL_v_1_0::correctEndianness(m_LinkLength);
  memcpy(bytes + pos, &m_LinkLengthTemp, sizeof(jUnsignedShortInteger));
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedShortInteger m_TwistAngleTemp;

  m_TwistAngleTemp = JSIDL_v_1_0::correctEndianness(m_TwistAngle);
  memcpy(bytes + pos, &m_TwistAngleTemp, sizeof(jUnsignedShortInteger));
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedShortInteger m_JointAngleTemp;

  m_JointAngleTemp = JSIDL_v_1_0::correctEndianness(m_JointAngle);
  memcpy(bytes + pos, &m_JointAngleTemp, sizeof(jUnsignedShortInteger));
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedInteger m_MinValueTemp;

  m_MinValueTemp = JSIDL_v_1_0::correctEndianness(m_MinValue);
  memcpy(bytes + pos, &m_MinValueTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_MaxValueTemp;

  m_MaxValueTemp = JSIDL_v_1_0::correctEndianness(m_MaxValue);
  memcpy(bytes + pos, &m_MaxValueTemp, sizeof(jUnsignedInteger));
  pos += sizeof(jUnsignedInteger);
  if (checkPresenceVector(0))
  {
    jUnsignedInteger m_MaxSpeedTemp;

    m_MaxSpeedTemp = JSIDL_v_1_0::correctEndianness(m_MaxSpeed);
    memcpy(bytes + pos, &m_MaxSpeedTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(1))
  {
    jUnsignedInteger m_MaxTorqueTemp;

    m_MaxTorqueTemp = JSIDL_v_1_0::correctEndianness(m_MaxForce);
    memcpy(bytes + pos, &m_MaxTorqueTemp, sizeof(jUnsignedInteger));
    pos += sizeof(jUnsignedInteger);
  }
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::decode(
    const unsigned char *bytes)
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
  jUnsignedShortInteger m_LinkLengthTemp;

  memcpy(&m_LinkLengthTemp, bytes + pos, sizeof(jUnsignedShortInteger));
  m_LinkLength = JSIDL_v_1_0::correctEndianness(m_LinkLengthTemp);
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedShortInteger m_TwistAngleTemp;

  memcpy(&m_TwistAngleTemp, bytes + pos, sizeof(jUnsignedShortInteger));
  m_TwistAngle = JSIDL_v_1_0::correctEndianness(m_TwistAngleTemp);
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedShortInteger m_JointAngleTemp;

  memcpy(&m_JointAngleTemp, bytes + pos, sizeof(jUnsignedShortInteger));
  m_JointAngle = JSIDL_v_1_0::correctEndianness(m_JointAngleTemp);
  pos += sizeof(jUnsignedShortInteger);
  jUnsignedInteger m_MinValueTemp;

  memcpy(&m_MinValueTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_MinValue = JSIDL_v_1_0::correctEndianness(m_MinValueTemp);
  pos += sizeof(jUnsignedInteger);
  jUnsignedInteger m_MaxValueTemp;

  memcpy(&m_MaxValueTemp, bytes + pos, sizeof(jUnsignedInteger));
  m_MaxValue = JSIDL_v_1_0::correctEndianness(m_MaxValueTemp);
  pos += sizeof(jUnsignedInteger);
  if (checkPresenceVector(0))
  {
    jUnsignedInteger m_MaxSpeedTemp;

    memcpy(&m_MaxSpeedTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_MaxSpeed = JSIDL_v_1_0::correctEndianness(m_MaxSpeedTemp);
    pos += sizeof(jUnsignedInteger);
  }
  if (checkPresenceVector(1))
  {
    jUnsignedInteger m_MaxTorqueTemp;

    memcpy(&m_MaxTorqueTemp, bytes + pos, sizeof(jUnsignedInteger));
    m_MaxForce = JSIDL_v_1_0::correctEndianness(m_MaxTorqueTemp);
    pos += sizeof(jUnsignedInteger);
  }
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec &ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::operator=(
    const PrismaticJointSpecificationRec &value)
{
  m_PresenceVector = value.m_PresenceVector;
  m_LinkLength = value.m_LinkLength;
  m_TwistAngle = value.m_TwistAngle;
  m_JointAngle = value.m_JointAngle;
  m_MinValue = value.m_MinValue;
  m_MaxValue = value.m_MaxValue;
  m_MaxSpeed = value.m_MaxSpeed;
  m_MaxForce = value.m_MaxForce;

  return *this;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::operator==(
    const PrismaticJointSpecificationRec &value) const
{
  if (m_PresenceVector != value.m_PresenceVector)
  {
    return false;
  }
  if (m_LinkLength != value.m_LinkLength)
  {
    return false;
  }
  if (m_TwistAngle != value.m_TwistAngle)
  {
    return false;
  }
  if (m_JointAngle != value.m_JointAngle)
  {
    return false;
  }
  if (m_MinValue != value.m_MinValue)
  {
    return false;
  }
  if (m_MaxValue != value.m_MaxValue)
  {
    return false;
  }
  if (m_MaxSpeed != value.m_MaxSpeed)
  {
    return false;
  }
  if (m_MaxForce != value.m_MaxForce)
  {
    return false;
  }

  return true;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::operator!=(
    const PrismaticJointSpecificationRec &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::PrismaticJointSpecificationRec()
{
  m_parent = NULL;
  m_PresenceVector = 0;
  m_LinkLength = 0;
  m_TwistAngle = 0;
  m_JointAngle = 0;
  m_MinValue = 0;
  m_MaxValue = 0;
  m_MaxSpeed = 0;
  m_MaxForce = 0;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::PrismaticJointSpecificationRec(
    const PrismaticJointSpecificationRec &value)
{
  /// Initiliaze the protected variables
  m_parent = NULL;
  m_PresenceVector = 0;
  m_LinkLength = 0;
  m_TwistAngle = 0;
  m_JointAngle = 0;
  m_MinValue = 0;
  m_MaxValue = 0;
  m_MaxSpeed = 0;
  m_MaxForce = 0;

  /// Copy the values
  m_PresenceVector = value.m_PresenceVector;
  m_LinkLength = value.m_LinkLength;
  m_TwistAngle = value.m_TwistAngle;
  m_JointAngle = value.m_JointAngle;
  m_MinValue = value.m_MinValue;
  m_MaxValue = value.m_MaxValue;
  m_MaxSpeed = value.m_MaxSpeed;
  m_MaxForce = value.m_MaxForce;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec::~PrismaticJointSpecificationRec()
{
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::PrismaticJointSpecificationRec* const ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::getPrismaticJointSpecificationRec()
{
  return &m_PrismaticJointSpecificationRec;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::setPrismaticJointSpecificationRec(
    const PrismaticJointSpecificationRec &value)
{
  m_PrismaticJointSpecificationRec = value;
  setParentPresenceVector();
  return 0;
}

jUnsignedByte ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::getFieldValue() const
{
  return m_FieldValue;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::setFieldValue(
    jUnsignedByte fieldValue)
{
  if (fieldValue > 1)
  {
    return 1;
  }

  m_FieldValue = fieldValue;
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
const unsigned int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::getSize()
{
  unsigned int size = 0;

  size += sizeof(jUnsignedByte);

  switch (m_FieldValue)
  {
    case 0:
      size += m_RevoluteJointSpecificationRec.getSize();
      break;
    case 1:
      size += m_PrismaticJointSpecificationRec.getSize();
      break;
  }

  return size;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::encode(
    unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  jUnsignedByte m_FieldValueTemp;

  m_FieldValueTemp = JSIDL_v_1_0::correctEndianness(m_FieldValue);
  memcpy(bytes + pos, &m_FieldValueTemp, sizeof(jUnsignedByte));
  pos += sizeof(jUnsignedByte);

  switch (m_FieldValue)
  {
    case 0:
      m_RevoluteJointSpecificationRec.encode(bytes + pos);
      pos += m_RevoluteJointSpecificationRec.getSize();
      break;
    case 1:
      m_PrismaticJointSpecificationRec.encode(bytes + pos);
      pos += m_PrismaticJointSpecificationRec.getSize();
      break;
  }
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::decode(
    const unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  jUnsignedByte m_FieldValueTemp;

  memcpy(&m_FieldValueTemp, bytes + pos, sizeof(jUnsignedByte));
  m_FieldValue = JSIDL_v_1_0::correctEndianness(m_FieldValueTemp);
  pos += sizeof(jUnsignedByte);

  switch (m_FieldValue)
  {
    case 0:
      m_RevoluteJointSpecificationRec.decode(bytes + pos);
      pos += m_RevoluteJointSpecificationRec.getSize();
      break;
    case 1:
      m_PrismaticJointSpecificationRec.decode(bytes + pos);
      pos += m_PrismaticJointSpecificationRec.getSize();
      break;
  }
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications &ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::operator=(
    const JointSpecifications &value)
{
  m_FieldValue = value.m_FieldValue;
  m_RevoluteJointSpecificationRec = value.m_RevoluteJointSpecificationRec;
  m_RevoluteJointSpecificationRec.setParent(this);
  m_PrismaticJointSpecificationRec = value.m_PrismaticJointSpecificationRec;
  m_PrismaticJointSpecificationRec.setParent(this);

  return *this;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::operator==(
    const JointSpecifications &value) const
{
  if (m_FieldValue != value.m_FieldValue)
  {
    return false;
  }
  if (m_RevoluteJointSpecificationRec != value.m_RevoluteJointSpecificationRec)
  {
    return false;
  }
  if (m_PrismaticJointSpecificationRec != value.m_PrismaticJointSpecificationRec)
  {
    return false;
  }

  return true;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::operator!=(
    const JointSpecifications &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::JointSpecifications()
{
  m_parent = NULL;
  m_FieldValue = 0;
  m_RevoluteJointSpecificationRec.setParent(this);
  /// No Initialization of m_RevoluteJointSpecificationRec necessary.
  m_PrismaticJointSpecificationRec.setParent(this);
  /// No Initialization of m_PrismaticJointSpecificationRec necessary.
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::JointSpecifications(
    const JointSpecifications &value)
{
  /// Initiliaze the protected variables
  m_parent = NULL;
  m_FieldValue = 0;
  m_RevoluteJointSpecificationRec.setParent(this);
  /// No Initialization of m_RevoluteJointSpecificationRec necessary.
  m_PrismaticJointSpecificationRec.setParent(this);
  /// No Initialization of m_PrismaticJointSpecificationRec necessary.

  /// Copy the values
  m_FieldValue = value.m_FieldValue;
  m_RevoluteJointSpecificationRec = value.m_RevoluteJointSpecificationRec;
  m_RevoluteJointSpecificationRec.setParent(this);
  m_PrismaticJointSpecificationRec = value.m_PrismaticJointSpecificationRec;
  m_PrismaticJointSpecificationRec.setParent(this);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications::~JointSpecifications()
{
}

unsigned int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::getNumberOfElements() const
{
  return (unsigned int)m_JointSpecifications.size();
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecifications* const ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::getElement(
    unsigned int index)
{
  return &m_JointSpecifications.at(index);
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::setElement(
    unsigned int index, const JointSpecifications &value)
{
  if (m_JointSpecifications.size() - 1 < index)
  {
    return 1;
  }

  m_JointSpecifications.at(index) = value;
  m_JointSpecifications.at(index).setParent(this);
  setParentPresenceVector();
  return 0;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::addElement(
    const JointSpecifications &value)
{
  m_JointSpecifications.push_back(value);
  m_JointSpecifications.back().setParent(this);
  setParentPresenceVector();
  return 0;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::deleteElement(
    unsigned int index)
{
  if (m_JointSpecifications.size() - 1 < index)
  {
    return 1;
  }

  m_JointSpecifications.erase(m_JointSpecifications.begin() + index);
  return 0;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::deleteLastElement()
{
  m_JointSpecifications.pop_back();
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
const unsigned int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::getSize()
{
  unsigned int size = 0;

  size += sizeof(jUnsignedByte);
  for (unsigned int i = 0; i < m_JointSpecifications.size(); i++)
  {
    size += m_JointSpecifications[i].getSize();
  }

  return size;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::encode(
    unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  jUnsignedByte size = (jUnsignedByte)m_JointSpecifications.size();
  memcpy(bytes, &size, sizeof(size));
  pos += sizeof(size);
  for (unsigned int i = 0; i < m_JointSpecifications.size(); i++)
  {
    m_JointSpecifications[i].encode(bytes + pos);
    pos += m_JointSpecifications[i].getSize();
  }
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::decode(
    const unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  jUnsignedByte size;
  memcpy(&size, bytes, sizeof(size));
  pos += sizeof(size);
  m_JointSpecifications.resize(size);
  for (unsigned int i = 0; i < m_JointSpecifications.size(); i++)
  {
    m_JointSpecifications[i].decode(bytes + pos);
    pos += m_JointSpecifications[i].getSize();
  }
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList &ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::operator=(
    const JointSpecificationList &value)
{
  m_JointSpecifications.clear();

  for (unsigned int i = 0; i < value.m_JointSpecifications.size(); i++)
  {
    m_JointSpecifications.push_back(value.m_JointSpecifications[i]);
    m_JointSpecifications[i].setParent(this);
  }

  return *this;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::operator==(
    const JointSpecificationList &value) const
{
  if (m_JointSpecifications.size() != value.m_JointSpecifications.size())
  {
    return false;
  }

  for (unsigned int i = 0; i < m_JointSpecifications.size(); i++)
  {
    if (m_JointSpecifications[i] != value.m_JointSpecifications[i])
    {
      return false;
    }
  }

  return true;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::operator!=(
    const JointSpecificationList &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecificationList()
{
  m_parent = NULL;
  for (unsigned int i = 0; i < m_JointSpecifications.size(); i++)
  {
    m_JointSpecifications[i].setParent(this);
  }
  /// No Initialization of m_JointSpecifications necessary.
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::JointSpecificationList(
    const JointSpecificationList &value)
{
  /// Initiliaze the protected variables
  m_parent = NULL;
  for (unsigned int i = 0; i < m_JointSpecifications.size(); i++)
  {
    m_JointSpecifications[i].setParent(this);
  }
  /// No Initialization of m_JointSpecifications necessary.

  /// Copy the values
  m_JointSpecifications.clear();

  for (unsigned int i = 0; i < value.m_JointSpecifications.size(); i++)
  {
    m_JointSpecifications.push_back(value.m_JointSpecifications[i]);
    m_JointSpecifications[i].setParent(this);
  }
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList::~JointSpecificationList()
{
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::JointSpecificationList* const ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::getJointSpecificationList()
{
  return &m_JointSpecificationList;
}

int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::setJointSpecificationList(
    const JointSpecificationList &value)
{
  m_JointSpecificationList = value;
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
const unsigned int ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::getSize()
{
  unsigned int size = 0;

  size += sizeof(jUnsignedByte);
  if (checkPresenceVector(0))
  {
    size += m_ManipulatorCoordinateSystemRec.getSize();
  }
  size += m_FirstJointParameters.getSize();
  size += m_JointSpecificationList.getSize();

  return size;
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::encode(unsigned char *bytes)
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
    m_ManipulatorCoordinateSystemRec.encode(bytes + pos);
    pos += m_ManipulatorCoordinateSystemRec.getSize();
  }
  m_FirstJointParameters.encode(bytes + pos);
  pos += m_FirstJointParameters.getSize();
  m_JointSpecificationList.encode(bytes + pos);
  pos += m_JointSpecificationList.getSize();
}

void ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::decode(const unsigned char *bytes)
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
    m_ManipulatorCoordinateSystemRec.decode(bytes + pos);
    pos += m_ManipulatorCoordinateSystemRec.getSize();
  }
  m_FirstJointParameters.decode(bytes + pos);
  pos += m_FirstJointParameters.getSize();
  m_JointSpecificationList.decode(bytes + pos);
  pos += m_JointSpecificationList.getSize();
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification &ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::operator=(
    const ReportManipulatorSpecification &value)
{
  m_PresenceVector = value.m_PresenceVector;
  m_ManipulatorCoordinateSystemRec = value.m_ManipulatorCoordinateSystemRec;
  m_ManipulatorCoordinateSystemRec.setParent(this);
  m_ManipulatorCoordinateSystemRec = value.m_ManipulatorCoordinateSystemRec;
  m_FirstJointParameters = value.m_FirstJointParameters;
  m_FirstJointParameters.setParent(this);
  m_FirstJointParameters = value.m_FirstJointParameters;
  m_JointSpecificationList = value.m_JointSpecificationList;
  m_JointSpecificationList.setParent(this);
  m_JointSpecificationList = value.m_JointSpecificationList;

  return *this;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::operator==(
    const ReportManipulatorSpecification &value) const
{
  if (m_PresenceVector != value.m_PresenceVector)
  {
    return false;
  }
  if (m_ManipulatorCoordinateSystemRec != value.m_ManipulatorCoordinateSystemRec)
  {
    return false;
  }

  if (m_ManipulatorCoordinateSystemRec != value.m_ManipulatorCoordinateSystemRec)
  {
    return false;
  }
  if (m_FirstJointParameters != value.m_FirstJointParameters)
  {
    return false;
  }

  if (m_FirstJointParameters != value.m_FirstJointParameters)
  {
    return false;
  }
  if (m_JointSpecificationList != value.m_JointSpecificationList)
  {
    return false;
  }

  if (m_JointSpecificationList != value.m_JointSpecificationList)
  {
    return false;
  }

  return true;
}

bool ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::operator!=(
    const ReportManipulatorSpecification &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ReportManipulatorSpecification()
{
  m_parent = NULL;
  m_PresenceVector = 0;
  m_ManipulatorCoordinateSystemRec.setParent(this);
  /// No Initialization of m_ManipulatorCoordinateSystemRec necessary.
  m_FirstJointParameters.setParent(this);
  /// No Initialization of m_FirstJointParameters necessary.
  m_JointSpecificationList.setParent(this);
  /// No Initialization of m_JointSpecificationList necessary.
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::ReportManipulatorSpecification(
    const ReportManipulatorSpecification &value)
{
  /// Initiliaze the protected variables
  m_parent = NULL;
  m_PresenceVector = 0;
  m_ManipulatorCoordinateSystemRec.setParent(this);
  /// No Initialization of m_ManipulatorCoordinateSystemRec necessary.
  m_FirstJointParameters.setParent(this);
  /// No Initialization of m_FirstJointParameters necessary.
  m_JointSpecificationList.setParent(this);
  /// No Initialization of m_JointSpecificationList necessary.

  /// Copy the values
  m_PresenceVector = value.m_PresenceVector;
  m_ManipulatorCoordinateSystemRec = value.m_ManipulatorCoordinateSystemRec;
  m_ManipulatorCoordinateSystemRec.setParent(this);
  m_ManipulatorCoordinateSystemRec = value.m_ManipulatorCoordinateSystemRec;
  m_FirstJointParameters = value.m_FirstJointParameters;
  m_FirstJointParameters.setParent(this);
  m_FirstJointParameters = value.m_FirstJointParameters;
  m_JointSpecificationList = value.m_JointSpecificationList;
  m_JointSpecificationList.setParent(this);
  m_JointSpecificationList = value.m_JointSpecificationList;
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification::~ReportManipulatorSpecification()
{
}

ReportManipulatorSpecifications::Body::ReportManipulatorSpecification* const ReportManipulatorSpecifications::Body::getReportManipulatorSpecification()
{
  return &m_ReportManipulatorSpecification;
}

int ReportManipulatorSpecifications::Body::setReportManipulatorSpecification(
    const ReportManipulatorSpecification &value)
{
  m_ReportManipulatorSpecification = value;
  setParentPresenceVector();
  return 0;
}

void ReportManipulatorSpecifications::Body::setParentPresenceVector()
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
const unsigned int ReportManipulatorSpecifications::Body::getSize()
{
  unsigned int size = 0;

  size += m_ReportManipulatorSpecification.getSize();

  return size;
}

void ReportManipulatorSpecifications::Body::encode(unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  m_ReportManipulatorSpecification.encode(bytes + pos);
  pos += m_ReportManipulatorSpecification.getSize();
}

void ReportManipulatorSpecifications::Body::decode(const unsigned char *bytes)
{

  if (bytes == NULL)
  {
    return;
  }

  int pos = 0;
  m_ReportManipulatorSpecification.decode(bytes + pos);
  pos += m_ReportManipulatorSpecification.getSize();
}

ReportManipulatorSpecifications::Body &ReportManipulatorSpecifications::Body::operator=(const Body &value)
{
  m_ReportManipulatorSpecification = value.m_ReportManipulatorSpecification;
  m_ReportManipulatorSpecification.setParent(this);
  /// This code is currently not supported

  return *this;
}

bool ReportManipulatorSpecifications::Body::operator==(const Body &value) const
{
  if (m_ReportManipulatorSpecification != value.m_ReportManipulatorSpecification)
  {
    return false;
  }
  /// This code is currently not supported
  return true;
}

bool ReportManipulatorSpecifications::Body::operator!=(const Body &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::Body::Body()
{
  m_ReportManipulatorSpecification.setParent(this);
  /// No Initialization of m_ReportManipulatorSpecification necessary.
}

ReportManipulatorSpecifications::Body::Body(const Body &value)
{
  /// Initiliaze the protected variables
  m_ReportManipulatorSpecification.setParent(this);
  /// No Initialization of m_ReportManipulatorSpecification necessary.

  /// Copy the values
  m_ReportManipulatorSpecification = value.m_ReportManipulatorSpecification;
  m_ReportManipulatorSpecification.setParent(this);
  /// This code is currently not supported
}

ReportManipulatorSpecifications::Body::~Body()
{
}

ReportManipulatorSpecifications::Body* const ReportManipulatorSpecifications::getBody()
{
  return &m_Body;
}

int ReportManipulatorSpecifications::setBody(const Body &value)
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
const unsigned int ReportManipulatorSpecifications::getSize()
{
  unsigned int size = 0;

  size += m_AppHeader.getSize();
  size += m_Body.getSize();

  return size;
}

void ReportManipulatorSpecifications::encode(unsigned char *bytes)
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

void ReportManipulatorSpecifications::decode(const unsigned char *bytes)
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

ReportManipulatorSpecifications &ReportManipulatorSpecifications::operator=(
    const ReportManipulatorSpecifications &value)
{
  m_AppHeader = value.m_AppHeader;
  m_Body = value.m_Body;

  return *this;
}

bool ReportManipulatorSpecifications::operator==(const ReportManipulatorSpecifications &value) const
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

bool ReportManipulatorSpecifications::operator!=(const ReportManipulatorSpecifications &value) const
{
  return !((*this) == value);
}

ReportManipulatorSpecifications::ReportManipulatorSpecifications()
{
  /// No Initialization of m_AppHeader necessary.
  /// No Initialization of m_Body necessary.
  m_IsCommand = false;
}

ReportManipulatorSpecifications::ReportManipulatorSpecifications(const ReportManipulatorSpecifications &value)
{
  /// Initiliaze the protected variables
  /// No Initialization of m_AppHeader necessary.
  /// No Initialization of m_Body necessary.
  m_IsCommand = false;

  /// Copy the values
  m_AppHeader = value.m_AppHeader;
  m_Body = value.m_Body;
}

ReportManipulatorSpecifications::~ReportManipulatorSpecifications()
{
}

}
