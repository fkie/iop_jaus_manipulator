#ifndef IOP_MANIPULATOR_CORE_FKIE_REPORTMANIPULATORSPECIFICATIONS_H
#define IOP_MANIPULATOR_CORE_FKIE_REPORTMANIPULATORSPECIFICATIONS_H

#include "JausUtils.h"
#include "Messages/Message.h"
namespace iop_manipulator_core_fkie
{

class DllExport ReportManipulatorSpecifications: public JTS::Message
{
public:
  static const int ID = 0x4600;

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
    class DllExport ReportManipulatorSpecification
    {
    public:
      class DllExport ManipulatorCoordinateSystemRec
      {
      public:
        void setParent(ReportManipulatorSpecification* parent);
        void setParentPresenceVector();
        double getManipulatorCoordinateSysX();
        int setManipulatorCoordinateSysX(double value);
        double getManipulatorCoordinateSysY();
        int setManipulatorCoordinateSysY(double value);
        double getManipulatorCoordinateSysZ();
        int setManipulatorCoordinateSysZ(double value);
        double getDComponentOfUnitQuaternionQ();
        int setDComponentOfUnitQuaternionQ(double value);
        double getAComponentOfUnitQuaternionQ();
        int setAComponentOfUnitQuaternionQ(double value);
        double getBComponentOfUnitQuaternionQ();
        int setBComponentOfUnitQuaternionQ(double value);
        double getCComponentOfUnitQuaternionQ();
        int setCComponentOfUnitQuaternionQ(double value);
        const unsigned int getSize();
        virtual void encode(unsigned char *bytes);
        virtual void decode(const unsigned char *bytes);
        ManipulatorCoordinateSystemRec &operator=(const ManipulatorCoordinateSystemRec &value);
        bool operator==(const ManipulatorCoordinateSystemRec &value) const;
        bool operator!=(const ManipulatorCoordinateSystemRec &value) const;
        ManipulatorCoordinateSystemRec();
        ManipulatorCoordinateSystemRec(const ManipulatorCoordinateSystemRec &value);
        virtual ~ManipulatorCoordinateSystemRec();

      protected:
        ReportManipulatorSpecification* m_parent;
        jUnsignedInteger m_ManipulatorCoordinateSysX;
        jUnsignedInteger m_ManipulatorCoordinateSysY;
        jUnsignedInteger m_ManipulatorCoordinateSysZ;
        jUnsignedInteger m_DComponentOfUnitQuaternionQ;
        jUnsignedInteger m_AComponentOfUnitQuaternionQ;
        jUnsignedInteger m_BComponentOfUnitQuaternionQ;
        jUnsignedInteger m_CComponentOfUnitQuaternionQ;
      };
      class DllExport FirstJointParameters
      {
      public:
        class DllExport RevoluteJoint1OffsetRec
        {
        public:
          void setParent(FirstJointParameters* parent);
          void setParentPresenceVector();
          jUnsignedByte getPresenceVector();
          bool checkPresenceVector(unsigned int index) const;
          double getJoint1Offset();
          int setJoint1Offset(double value);
          bool isJoint1MinValueValid() const;
          double getJoint1MinValue();
          int setJoint1MinValue(double value);
          bool isJoint1MaxValueValid() const;
          double getJoint1MaxValue();
          int setJoint1MaxValue(double value);
          bool isJoint1MaxSpeedValid() const;
          double getJoint1MaxSpeed();
          int setJoint1MaxSpeed(double value);
          bool isJoint1MaxTorqueValid() const;
          double getJoint1MaxTorque();
          int setJoint1MaxTorque(double value);
          const unsigned int getSize();
          virtual void encode(unsigned char *bytes);
          virtual void decode(const unsigned char *bytes);
          RevoluteJoint1OffsetRec &operator=(const RevoluteJoint1OffsetRec &value);
          bool operator==(const RevoluteJoint1OffsetRec &value) const;
          bool operator!=(const RevoluteJoint1OffsetRec &value) const;
          RevoluteJoint1OffsetRec();
          RevoluteJoint1OffsetRec(const RevoluteJoint1OffsetRec &value);
          virtual ~RevoluteJoint1OffsetRec();

        protected:
          int setPresenceVector(unsigned int index);

          FirstJointParameters* m_parent;
          jUnsignedByte m_PresenceVector;
          jUnsignedShortInteger m_Joint1Offset;
          jUnsignedInteger m_Joint1MinValue;
          jUnsignedInteger m_Joint1MaxValue;
          jUnsignedInteger m_Joint1MaxSpeed;
          jUnsignedInteger m_Joint1MaxTorque;
        };
        class DllExport PrismaticJoint1AngleRec
        {
        public:
          void setParent(FirstJointParameters* parent);
          void setParentPresenceVector();
          jUnsignedByte getPresenceVector();
          bool checkPresenceVector(unsigned int index) const;
          double getJoint1Angle();
          int setJoint1Angle(double value);
          double getJoint1MinValue();
          int setJoint1MinValue(double value);
          double getJoint1MaxValue();
          int setJoint1MaxValue(double value);
          bool isJoint1MaxSpeedValid() const;
          double getJoint1MaxSpeed();
          int setJoint1MaxSpeed(double value);
          bool isJoint1MaxForceValid() const;
          double getJoint1MaxForce();
          int setJoint1MaxForce(double value);
          const unsigned int getSize();
          virtual void encode(unsigned char *bytes);
          virtual void decode(const unsigned char *bytes);
          PrismaticJoint1AngleRec &operator=(const PrismaticJoint1AngleRec &value);
          bool operator==(const PrismaticJoint1AngleRec &value) const;
          bool operator!=(const PrismaticJoint1AngleRec &value) const;
          PrismaticJoint1AngleRec();
          PrismaticJoint1AngleRec(const PrismaticJoint1AngleRec &value);
          virtual ~PrismaticJoint1AngleRec();

        protected:
          int setPresenceVector(unsigned int index);

          FirstJointParameters* m_parent;
          jUnsignedByte m_PresenceVector;
          jUnsignedShortInteger m_Joint1Angle;
          jUnsignedInteger m_Joint1MinValue;
          jUnsignedInteger m_Joint1MaxValue;
          jUnsignedInteger m_Joint1MaxSpeed;
          jUnsignedInteger m_Joint1MaxForce;
        };

        void setParent(ReportManipulatorSpecification* parent);
        void setParentPresenceVector();
        RevoluteJoint1OffsetRec* const getRevoluteJoint1OffsetRec();
        int setRevoluteJoint1OffsetRec(const RevoluteJoint1OffsetRec &value);
        PrismaticJoint1AngleRec* const getPrismaticJoint1AngleRec();
        int setPrismaticJoint1AngleRec(const PrismaticJoint1AngleRec &value);
        jUnsignedByte getFieldValue() const;
        int setFieldValue(jUnsignedByte fieldValue);
        const unsigned int getSize();
        virtual void encode(unsigned char *bytes);
        virtual void decode(const unsigned char *bytes);
        FirstJointParameters &operator=(const FirstJointParameters &value);
        bool operator==(const FirstJointParameters &value) const;
        bool operator!=(const FirstJointParameters &value) const;
        FirstJointParameters();
        FirstJointParameters(const FirstJointParameters &value);
        virtual ~FirstJointParameters();

      protected:
        ReportManipulatorSpecification* m_parent;
        jUnsignedByte m_FieldValue;
        RevoluteJoint1OffsetRec m_RevoluteJoint1OffsetRec;
        PrismaticJoint1AngleRec m_PrismaticJoint1AngleRec;
      };
      class DllExport JointSpecificationList
      {
      public:
        class DllExport JointSpecifications
        {
        public:
          class DllExport RevoluteJointSpecificationRec
          {
          public:
            void setParent(JointSpecifications* parent);
            void setParentPresenceVector();
            jUnsignedByte getPresenceVector();
            bool checkPresenceVector(unsigned int index) const;
            double getLinkLength();
            int setLinkLength(double value);
            double getTwistAngle();
            int setTwistAngle(double value);
            double getJointOffset();
            int setJointOffset(double value);
            bool isMinValueValid() const;
            double getMinValue();
            int setMinValue(double value);
            bool isMaxValueValid() const;
            double getMaxValue();
            int setMaxValue(double value);
            bool isMaxSpeedValid() const;
            double getMaxSpeed();
            int setMaxSpeed(double value);
            bool isMaxTorqueValid() const;
            double getMaxTorque();
            int setMaxTorque(double value);
            const unsigned int getSize();
            virtual void encode(unsigned char *bytes);
            virtual void decode(const unsigned char *bytes);
            RevoluteJointSpecificationRec &operator=(const RevoluteJointSpecificationRec &value);
            bool operator==(const RevoluteJointSpecificationRec &value) const;
            bool operator!=(const RevoluteJointSpecificationRec &value) const;
            RevoluteJointSpecificationRec();
            RevoluteJointSpecificationRec(const RevoluteJointSpecificationRec &value);
            virtual ~RevoluteJointSpecificationRec();

          protected:
            int setPresenceVector(unsigned int index);

            JointSpecifications* m_parent;
            jUnsignedByte m_PresenceVector;
            jUnsignedShortInteger m_LinkLength;
            jUnsignedShortInteger m_TwistAngle;
            jUnsignedShortInteger m_JointOffset;
            jUnsignedInteger m_MinValue;
            jUnsignedInteger m_MaxValue;
            jUnsignedInteger m_MaxSpeed;
            jUnsignedInteger m_MaxTorque;
          };
          class DllExport PrismaticJointSpecificationRec
          {
          public:
            void setParent(JointSpecifications* parent);
            void setParentPresenceVector();
            jUnsignedByte getPresenceVector();
            bool checkPresenceVector(unsigned int index) const;
            double getLinkLength();
            int setLinkLength(double value);
            double getTwistAngle();
            int setTwistAngle(double value);
            double getJointAngle();
            int setJointAngle(double value);
            double getMinValue();
            int setMinValue(double value);
            double getMaxValue();
            int setMaxValue(double value);
            bool isMaxSpeedValid() const;
            double getMaxSpeed();
            int setMaxSpeed(double value);
            bool isMaxForceValid() const;
            double getMaxForce();
            int setMaxForce(double value);
            const unsigned int getSize();
            virtual void encode(unsigned char *bytes);
            virtual void decode(const unsigned char *bytes);
            PrismaticJointSpecificationRec &operator=(const PrismaticJointSpecificationRec &value);
            bool operator==(const PrismaticJointSpecificationRec &value) const;
            bool operator!=(const PrismaticJointSpecificationRec &value) const;
            PrismaticJointSpecificationRec();
            PrismaticJointSpecificationRec(const PrismaticJointSpecificationRec &value);
            virtual ~PrismaticJointSpecificationRec();

          protected:
            int setPresenceVector(unsigned int index);

            JointSpecifications* m_parent;
            jUnsignedByte m_PresenceVector;
            jUnsignedShortInteger m_LinkLength;
            jUnsignedShortInteger m_TwistAngle;
            jUnsignedShortInteger m_JointAngle;
            jUnsignedInteger m_MinValue;
            jUnsignedInteger m_MaxValue;
            jUnsignedInteger m_MaxSpeed;
            jUnsignedInteger m_MaxForce;
          };

          void setParent(JointSpecificationList* parent);
          void setParentPresenceVector();
          RevoluteJointSpecificationRec* const getRevoluteJointSpecificationRec();
          int setRevoluteJointSpecificationRec(const RevoluteJointSpecificationRec &value);
          PrismaticJointSpecificationRec* const getPrismaticJointSpecificationRec();
          int setPrismaticJointSpecificationRec(const PrismaticJointSpecificationRec &value);
          jUnsignedByte getFieldValue() const;
          int setFieldValue(jUnsignedByte fieldValue);
          const unsigned int getSize();
          virtual void encode(unsigned char *bytes);
          virtual void decode(const unsigned char *bytes);
          JointSpecifications &operator=(const JointSpecifications &value);
          bool operator==(const JointSpecifications &value) const;
          bool operator!=(const JointSpecifications &value) const;
          JointSpecifications();
          JointSpecifications(const JointSpecifications &value);
          virtual ~JointSpecifications();

        protected:
          JointSpecificationList* m_parent;
          jUnsignedByte m_FieldValue;
          RevoluteJointSpecificationRec m_RevoluteJointSpecificationRec;
          PrismaticJointSpecificationRec m_PrismaticJointSpecificationRec;
        };

        void setParent(ReportManipulatorSpecification* parent);
        void setParentPresenceVector();
        unsigned int getNumberOfElements() const;
        JointSpecifications* const getElement(unsigned int index);
        int setElement(unsigned int index, const JointSpecifications &value);
        int addElement(const JointSpecifications &value);
        int deleteElement(unsigned int index);
        int deleteLastElement();
        const unsigned int getSize();
        virtual void encode(unsigned char *bytes);
        virtual void decode(const unsigned char *bytes);
        JointSpecificationList &operator=(const JointSpecificationList &value);
        bool operator==(const JointSpecificationList &value) const;
        bool operator!=(const JointSpecificationList &value) const;
        JointSpecificationList();
        JointSpecificationList(const JointSpecificationList &value);
        virtual ~JointSpecificationList();

      protected:
        ReportManipulatorSpecification* m_parent;
        std::vector<JointSpecifications> m_JointSpecifications;
      };

      void setParent(Body* parent);
      void setParentPresenceVector();
      jUnsignedByte getPresenceVector();
      bool checkPresenceVector(unsigned int index) const;
      bool isManipulatorCoordinateSystemRecValid() const;
      ManipulatorCoordinateSystemRec* const getManipulatorCoordinateSystemRec();
      int setManipulatorCoordinateSystemRec(const ManipulatorCoordinateSystemRec &value);
      FirstJointParameters* const getFirstJointParameters();
      int setFirstJointParameters(const FirstJointParameters &value);
      JointSpecificationList* const getJointSpecificationList();
      int setJointSpecificationList(const JointSpecificationList &value);
      const unsigned int getSize();
      virtual void encode(unsigned char *bytes);
      virtual void decode(const unsigned char *bytes);
      ReportManipulatorSpecification &operator=(const ReportManipulatorSpecification &value);
      bool operator==(const ReportManipulatorSpecification &value) const;
      bool operator!=(const ReportManipulatorSpecification &value) const;
      ReportManipulatorSpecification();
      ReportManipulatorSpecification(const ReportManipulatorSpecification &value);
      virtual ~ReportManipulatorSpecification();

    protected:
      int setPresenceVector(unsigned int index);

      Body* m_parent;
      jUnsignedByte m_PresenceVector;
      ManipulatorCoordinateSystemRec m_ManipulatorCoordinateSystemRec;
      FirstJointParameters m_FirstJointParameters;
      JointSpecificationList m_JointSpecificationList;
    };

    ReportManipulatorSpecification* const getReportManipulatorSpecification();
    int setReportManipulatorSpecification(const ReportManipulatorSpecification &value);
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
    ReportManipulatorSpecification m_ReportManipulatorSpecification;
  };

  unsigned int getID()
  { return ID;};
  AppHeader* const getAppHeader();
  int setAppHeader(const AppHeader &value);
  Body* const getBody();
  int setBody(const Body &value);
  const unsigned int getSize();
  virtual void encode(unsigned char *bytes);
  virtual void decode(const unsigned char *bytes);
  ReportManipulatorSpecifications &operator=(const ReportManipulatorSpecifications &value);
  bool operator==(const ReportManipulatorSpecifications &value) const;
  bool operator!=(const ReportManipulatorSpecifications &value) const;
  ReportManipulatorSpecifications();
  ReportManipulatorSpecifications(const ReportManipulatorSpecifications &value);
  virtual ~ReportManipulatorSpecifications();

protected:
  AppHeader m_AppHeader;
  Body m_Body;
};

}

#endif // IOP_MANIPULATOR_CORE_FKIE_REPORTMANIPULATORSPECIFICATIONS_H
