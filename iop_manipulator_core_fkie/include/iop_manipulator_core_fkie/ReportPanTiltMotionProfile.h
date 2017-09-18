#ifndef IOP_MANIPULATOR_CORE_FKIE_REPORTPANTILTMOTIONPROFILE_H
#define IOP_MANIPULATOR_CORE_FKIE_REPORTPANTILTMOTIONPROFILE_H

#include "JausUtils.h"
#include "Messages/Message.h"
namespace iop_manipulator_core_fkie
{

class DllExport ReportPanTiltMotionProfile: public JTS::Message
{
public:
	static const int ID = 0x4627;

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
		class DllExport PanTiltMotionProfileRec
		{
		public:
			void setParent(Body* parent);
			void setParentPresenceVector();
			double getJoint1MaxSpeed();
			int setJoint1MaxSpeed(double value);
			double getJoint1MaxAccelerationRate();
			int setJoint1MaxAccelerationRate(double value);
			double getJoint1MaxDecelerationRate();
			int setJoint1MaxDecelerationRate(double value);
			double getJoint2MaxSpeed();
			int setJoint2MaxSpeed(double value);
			double getJoint2MaxAccelerationRate();
			int setJoint2MaxAccelerationRate(double value);
			double getJoint2MaxDecelerationRate();
			int setJoint2MaxDecelerationRate(double value);
			const unsigned int getSize();
			virtual void encode(unsigned char *bytes);
			virtual void decode(const unsigned char *bytes);
			PanTiltMotionProfileRec &operator=(const PanTiltMotionProfileRec &value);
			bool operator==(const PanTiltMotionProfileRec &value) const;
			bool operator!=(const PanTiltMotionProfileRec &value) const;
			PanTiltMotionProfileRec();
			PanTiltMotionProfileRec(const PanTiltMotionProfileRec &value);
			virtual ~PanTiltMotionProfileRec();

		protected:
			Body* m_parent;
			jUnsignedInteger m_Joint1MaxSpeed;
			jUnsignedInteger m_Joint1MaxAccelerationRate;
			jUnsignedInteger m_Joint1MaxDecelerationRate;
			jUnsignedInteger m_Joint2MaxSpeed;
			jUnsignedInteger m_Joint2MaxAccelerationRate;
			jUnsignedInteger m_Joint2MaxDecelerationRate;
		};

		PanTiltMotionProfileRec* const getPanTiltMotionProfileRec();
		int setPanTiltMotionProfileRec(const PanTiltMotionProfileRec &value);
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
		PanTiltMotionProfileRec m_PanTiltMotionProfileRec;
	};

	unsigned int getID() { return ID; };
	AppHeader* const getAppHeader();
	int setAppHeader(const AppHeader &value);
	Body* const getBody();
	int setBody(const Body &value);
	const unsigned int getSize();
	virtual void encode(unsigned char *bytes);
	virtual void decode(const unsigned char *bytes);
	ReportPanTiltMotionProfile &operator=(const ReportPanTiltMotionProfile &value);
	bool operator==(const ReportPanTiltMotionProfile &value) const;
	bool operator!=(const ReportPanTiltMotionProfile &value) const;
	ReportPanTiltMotionProfile();
	ReportPanTiltMotionProfile(const ReportPanTiltMotionProfile &value);
	virtual ~ReportPanTiltMotionProfile();

protected:
	AppHeader m_AppHeader;
	Body m_Body;
};

}

#endif // IOP_MANIPULATOR_CORE_FKIE_REPORTPANTILTMOTIONPROFILE_H
