#ifndef __TABLEMATRIX_H
#define __TABLEMATRIX_H

#include "CadApi.h"

namespace bcholmes {
	namespace fcw2svg {

		class TableMatrix {
			public:
				float m_m11;    		// first column
				float m_m21;
				float m_m31;
				float m_m41;
				float m_m12;    		// second column
				float m_m22;
				float m_m32;
				float m_m42;
				float m_m13;		    // third column
				float m_m23;
				float m_m33;
				float m_m43;

				TableMatrix(float m11, float m21, float m31, float m41, 
					float m12, float m22, float m32, float m42, 
					float m13, float m23, float m33, float m43) 
					: m_m11(m11), m_m21(m21), m_m31(m31), m_m41(m41), 
					m_m12(m12), m_m22(m22), m_m32(m32), m_m42(m42), 
					m_m13(m13), m_m23(m23), m_m33(m33), m_m43(m43) {}
				TableMatrix(const TableMatrix& other) 
					: m_m11(other.m_m11), m_m21(other.m_m21), m_m31(other.m_m31), m_m41(other.m_m41), 
					m_m12(other.m_m12), m_m22(other.m_m22), m_m32(other.m_m32), m_m42(other.m_m42), 
					m_m13(other.m_m13), m_m23(other.m_m23), m_m33(other.m_m33), m_m43(other.m_m43) {}
				~TableMatrix() {}

				static TableMatrix from(SYMTMAT tmat) {
					return TableMatrix(tmat.m11, tmat.m21, tmat.m31, tmat.m41,
						tmat.m12, tmat.m22, tmat.m32, tmat.m42,
						tmat.m13, tmat.m23, tmat.m33, tmat.m43);
				}
			};
	}
}

#endif