#ifndef __DRAWING_H
#define __DRAWING_H

#include <string>
#include "CoordinateSystem.h"
#include "Paint.h"
#include "SvgElement.h"
#include "SvgDocument.h"

namespace bcholmes {
	namespace fcw2svg {
	
		class Fcw;

		class Drawing : public CoordinateSystem {
			private:
				CoordinateSystem& m_coordinateSystem;
				float m_width;
				float m_height;
				Fcw& m_fcw;
				SvgDocument& m_document;
			public:
				Drawing(CoordinateSystem& coordinateSystem, SvgDocument& document, Fcw& fcw, float width, float height) 
					: CoordinateSystem(), m_coordinateSystem(coordinateSystem), m_width(width),
					m_height(height), m_fcw(fcw), m_document(document) {}
				Drawing(const Drawing& drawing) : CoordinateSystem(drawing),
					m_coordinateSystem(drawing.m_coordinateSystem), m_width(drawing.m_width), 
					m_height(drawing.m_height), m_fcw(drawing.m_fcw), m_document(drawing.m_document) {}
				~Drawing() {}
				
				std::string getColor(short color);
				float getBaseStroke();
				Paint getFillStyle(short fillStyle, string color);

				virtual Point map(Point point) { return m_coordinateSystem.map(point); }
				virtual float mapX(float x) { return m_coordinateSystem.mapX(x); }
				virtual float mapY(float y) { return m_coordinateSystem.mapY(y); }
				float getWidth() { return m_width; }
				float getHeight() { return m_height; }
				
				void initializeSvgDimensions(SvgElement& element);
		};
	}
}

#endif