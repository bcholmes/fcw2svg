#include <iostream>
#include "Fcw.h"
#include "CommonHeader.h"
#include "ShapeFactory.h"
#include "SvgDocument.h"
#include "Group.h"
#include "NumberUtil.h"
#include "InfoBlockFillDetails.h"

using namespace std;

namespace bcholmes {
	namespace fcw2svg {

		Fcw::Fcw(string fileName, string svgFileName) : m_fileName(fileName), m_svgFileName(svgFileName) {
			for (int i = 0; i < 18; i++) {
				m_infoBlocks[i] = NULL;
			}
			m_stack.push(&m_entities);
		}

		void Fcw::startSubList() {
			vector<Shape*>* e = m_stack.top();
			Shape* shape = e->at(e->size()-1);
			if (shape->isGroup()) {
				Group* group = (Group*) shape;
				m_stack.push(group->getSublist());
			}
		}

		void Fcw::endSubList() {
			m_stack.pop();
		}

		void Fcw::addInfoBlock(void* infoBlock) {
			InfoBlock* block = InfoBlock::from(infoBlock);
			if (block != NULL) {
				m_infoBlocks[block->getType()] = block;
			}
		}

		void Fcw::addEntity(void* entity) {
			vector<Shape*>* e = m_stack.top();
			CommonHeader header = CommonHeader::from((CSTUFF*) entity);
			e->push_back(ShapeFactory::createShape(header, (unsigned char*) entity));
		}

		int Fcw::decodeBuffer(string file, string outputFile, size_t bsize, unsigned char * b) {
			Fcw fcw(file, outputFile);
			for (int offset = 0; offset < bsize; ) {
				CommonHeader header = CommonHeader::from((CSTUFF*) (b + offset));
				
				vector<Shape*>* e = fcw.m_stack.top();
				
				if (header.getSize() == 0) {
					break;
				} else if (header.isSubListMarker()) {
					if (header.getType() == 0) {
						fcw.startSubList();
					} else {
						fcw.endSubList();
					}
				} else if (header.isInfoBlockType()) {
					InfoBlock* block = InfoBlock::from(b + offset);
					if (block != NULL) {
						fcw.m_infoBlocks[block->getType()] = block;
					}
				} else {
					e->push_back(ShapeFactory::createShape(header, b + offset));
				}
				offset += header.getSize();
			}
			
			fcw.toSvg();
			return 0;
		}
	
		void Fcw::toSvg() {
			InfoBlockHeader* header = getInfoBlockHeader();
			SvgDocument document;
			
			Fcw::SvgCoordinateSystem coord(header->getLow(), header->getHigh());
			Drawing drawing(coord, document, *this, header->getWidth(), header->getHeight());
			Fcw::SymbolCoordinateSystem symbolCoord;
			Drawing symbolDrawing(symbolCoord, document, *this, header->getWidth(), header->getHeight());
			
			SvgElement element = document.getDocumentElement();
			drawing.initializeSvgDimensions(element);
			SvgElement defs = document.getDefsElement();
			for (int i = 0; i < m_entities.size(); i++) {
				Shape* shape = m_entities[i];
				if (shape->isSymbolDefinition()) {
					shape->appendAsXml(defs, symbolDrawing);
				} else {
					shape->appendAsXml(element, drawing);
				}
			}
			document.writeFile(m_svgFileName);
		}
		
		Fcw::~Fcw() {
			for (int i = 0; i < m_entities.size(); i++) {
				Shape* shape = m_entities[i];
				delete shape;
			}
			for (int i = 0; i < 18; i++) {
				InfoBlock* block = m_infoBlocks[i];
				if (block != NULL) {
					delete block;
				}
			}
		}
		
		SymbolDefinition* Fcw::findSymbol(const string& name) {
			SymbolDefinition* result = NULL;
			for (int i = 0; i < m_entities.size(); i++) {
				Shape* shape = m_entities[i];
				if (shape->isSymbolDefinition() && 
						name.compare(((SymbolDefinition*) shape)->getName()) == 0) {
					result = (SymbolDefinition*) shape;
					break;
				}
			}
			return result;
		}
		
		
		Paint Fcw::getFillStyle(SvgElement& defs, short fillStyle, string color) {
			InfoBlockFillDetails* infoBlock = (InfoBlockFillDetails*) m_infoBlocks[IB_FSTYLE];
		
			InfoBlockFillDetails::FillStyle* style = infoBlock->getStyle(fillStyle);
			if (style == NULL) {
				return Paint(color);
			} else if (style->isSymbol() || style->isPattern()) {
				return style->initialize(defs, *this, color);
			} else {
				return Paint("yellow");
			}
	}
	}
}

