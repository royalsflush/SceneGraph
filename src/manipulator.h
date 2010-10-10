// manipulator.h
// Visualização 3D
// W. Celes - celes@inf.puc-rio.br
// PUC-Rio, Jan 2008

#ifndef V_MANIPULATOR_H
#define V_MANIPULATOR_H

class VManipulator {
	static VManipulator* s_current;
	float m_matrix[16];
	float m_zcenter;
	
	public:
		static VManipulator* GetCurrent ();
		static void SetCurrent (VManipulator* manip);

		VManipulator();
		void SetZCenter (float zcenter);
		void Load ();
		void Identity();
		void Rotate (float angle, float rx, float ry, float rz);
		void Scale (float sx, float sy, float sz);
};

#endif
