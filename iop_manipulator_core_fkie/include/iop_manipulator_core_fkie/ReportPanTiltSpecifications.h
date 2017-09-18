#ifndef IOP_MANIPULATOR_CORE_FKIE_REPORTPANTILTSPECIFICATIONS_H
#define IOP_MANIPULATOR_CORE_FKIE_REPORTPANTILTSPECIFICATIONS_H

#include "JausUtils.h"
#include "Messages/Message.h"
namespace iop_manipulator_core_fkie
{

class DllExport ReportPanTiltSpecifications: public JTS::Message
{
public:
	static const int ID = 0x4620;

	class DllExport AppHeader
	{
	public:
		class DllExport HeaderRec
		{
		public:
			void setParent(AppHeader* parent);
			void setParentPresenceVector();
			jUnsignedShortInteger getMessageID();
			int setMessageID(jUnsignedShortInteger value);
			const unsigned int getSize();
			virtual void encode(unsigned char *bytes);
			virtual void decode(const unsigned char *bytes);
			HeaderRec &operator=(const HeaderRec &value);
			bool operator==(const HeaderRec &value) const;
			bool operator!=(const HeaderRec &value) const;
			HeaderRec();
			HeaderRec(const HeaderRec &value);
			virtual ~HeaderRec();

		protected:
			AppHeader* m_parent;
			jUnsignedShortInteger m_MessageID;
		};

		HeaderRec* const getHeaderRec();
		int setHeaderRec(const HeaderRec &value);
		void setParentPresenceVector();
		const unsigned int getSize();
		virtual void encode(unsigned char *bytes);
		virtual void decode(const unsigned char *bytes);
		AppHeader &operator=(const AppHeader &value);
		bool operator==(const AppHeader &value) const;
		bool operator!=(const AppHeader &value) const;
		AppHeader();
		AppHeader(const AppHeader &value);
		virtual ~AppHeader();

	protected:
		HeaderRec m_HeaderRec;
	};
	class DllExport Body
	{
	public:
		class DllExport ReportPanTiltSpecificationsRec
		{
		public:
			void setParent(Body* parent);
			void setParentPresenceVector();
			jUnsignedByte getPresenceVector();
			bool checkPresenceVector(unsigned int index) const;
			bool isPanTiltCoordinateSysXValid() const;
			double getPanTiltCoordinateSysX();
			int setPanTiltCoordinateSysX(double value);
			bool isPanTiltCoordinateSysYValid() const;
			double getPanTiltCoordinateSysY();
			int setPanTiltCoordinateSysY(double value);
			bool isPanTiltCoordinateSysZValid() const;
			double getPanTiltCoordinateSysZ();
			int setPanTiltCoordinateSysZ(double value);
			bool isDComponentOfUnitQuaternionQValid() const;
			double getDComponentOfUnitQuaternionQ();
			int setDComponentOfUnitQuaternionQ(double value);
			bool isAComponentOfUnitQuaternionQValid() const;
			double getAComponentOfUnitQuaternionQ();
			int setAComponentOfUnitQuaternionQ(double value);
			bool isBComponentOfUnitQuaternionQValid() const;
			double getBComponentOfUnitQuaternionQ();
			int setBComponentOfUnitQuaternionQ(double value);
			bool isCComponentOfUnitQuaternionQValid() const;
			double getCComponentOfUnitQuaternionQ();
			int setCComponentOfUnitQuaternionQ(double value);
			double getJoint1MinValue();
			int setJoint1MinValue(double value);
			double getJoint1MaxValue();
			int setJoint1MaxValue(double value);
			double getJoint1MaxSpeed();
			int setJoint1MaxSpeed(double value);
			double getJoint2MinValue();
			int setJoint2MinValue(double value);
			double getJoint2MaxValue();
			int setJoint2MaxValue(double value);
			double getJoint2MaxSpeed();
			int setJoint2MaxSpeed(double value);
			const unsigned int getSize();
			virtual void encode(unsigned char *bytes);
			virtual void decode(const unsigned char *bytes);
			ReportPanTiltSpecificationsRec &operator=(const ReportPanTiltSpecificationsRec &value);
			bool operator==(const ReportPanTiltSpecificationsRec &value) const;
			bool operator!=(const ReportPanTiltSpecificationsRec &value) const;
			ReportPanTiltSpecificationsRec();
			ReportPanTiltSpecificationsRec(const ReportPanTiltSpecificationsRec &value);
			virtual ~ReportPanTiltSpecificationsRec();

		protected:
			int setPresenceVector(unsigned int index);

			Body* m_parent;
			jUnsignedByte m_PresenceVector;
			jUnsignedInteger m_PanTiltCoordinateSysX;
			jUnsignedInteger m_PanTiltCoordinateSysY;
			jUnsignedInteger m_PanTiltCoordinateSysZ;
			jUnsignedInteger m_DComponentOfUnitQuaternionQ;
			jUnsignedInteger m_AComponentOfUnitQuaternionQ;
			jUnsignedInteger m_BComponentOfUnitQuaternionQ;
			jUnsignedInteger m_CComponentOfUnitQuaternionQ;
			jUnsignedInteger m_Joint1MinValue;
			jUnsignedInteger m_Joint1MaxValue;
			jUnsignedInteger m_Joint1MaxSpeed;
			jUnsignedInteger m_Joint2MinValue;
			jUnsignedInteger m_Joint2MaxValue;
			jUnsignedInteger m_Joint2MaxSpeed;
		};

		ReportPanTiltSpecificationsRec* const getReportPanTiltSpecificationsRec();
		int setReportPanTiltSpecificationsRec(const ReportPanTiltSpecificationsRec &value);
		void setParentPresenceVector();
		const unsigned int getSize();
		virtual void encode(unsigned char *bytes);
		virtual void decode(const unsigned char *bytes);
		Body &operator=(const Body &value);
		bool operator==(const Body &value) const;
		bool operator!=(const Body &value) const;
		Body();
		Body(const Body &value);
		virtual ~Body();

	protected:
		ReportPanTiltSpecificationsRec m_ReportPanTiltSpecificationsRec;
	};

	unsigned int getID() { return ID; };
	AppHeader* const getAppHeader();
	int setAppHeader(const AppHeader &value);
	Body* const getBody();
	int setBody(const Body &value);
	const unsigned int getSize();
	virtual void encode(unsigned char *bytes);
	virtual void decode(const unsigned char *bytes);
	ReportPanTiltSpecifications &operator=(const ReportPanTiltSpecifications &value);
	bool operator==(const ReportPanTiltSpecifications &value) const;
	bool operator!=(const ReportPanTiltSpecifications &value) const;
	ReportPanTiltSpecifications();
	ReportPanTiltSpecifications(const ReportPanTiltSpecifications &value);
	virtual ~ReportPanTiltSpecifications();

protected:
	AppHeader m_AppHeader;
	Body m_Body;
};

}

#endif // IOP_MANIPULATOR_CORE_FKIE_REPORTPANTILTSPECIFICATIONS_H
