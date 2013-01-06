#include <math.h>
#include "Drawing.h"
#include "NumberUtil.h"
#include "Fcw.h"

using std::string;

namespace bcholmes {
	namespace fcw2svg {

int DefaultPalette[256]={
  0x000000000, // 0 = black
  0x00000FF00, // 1 = green
  0x000E00000, // 2 = red
  0x0000000FF, // 3 = blue
  0x000FFFF00, // 4 = yellow
  0x00000FFFF, // 5 = cyan
  0x000FF00FF, // 6 = magenta
  0x000AF00FF, // 7 = purple
  0x000FF6700, // 8 = orange
  0x0006888FF, // 9 = light blue
  0x000F89858, // 10 = sand
  0x000A84800, // 11 = brown
  0x000888838, // 12 = olive green
  0x000006838, // 13 = forest green
  0x000606060, // 14 = grey
  0x000FFFFFF, // 15 = white
  
  0x000BFBFBF, // 16 = button face
  0x000020202, // 17 = button text
  0x0007f7f7f, // 18 = button shadow
  0x000FFF8E0, // 19 = eggshell paper color
  
  0x000008080, // 20
  0x000E87640, // 21
  0x000678096, // 22
  0x000509E65, // 23
  0x000B1403D, // 24
  0x000A84A79, // 25
  0x000408080, // 26
  0x0004393BE, // 27
  0x0008080C0, // 28
  0x000FFF0BD, // 29
  0x00056ABAB, // 30
  0x000FFF8E0, // 31
  
  0x00025160B, // 32
  0x000372110, // 33
  0x000492C15, // 34
  0x0005B371A, // 35
  0x0006D421F, // 36
  0x0007F4D24, // 37
  0x000915829, // 38
  0x000A3632E, // 39
  0x000AD7445, // 40
  0x000B7855C, // 41
  0x000C19673, // 42
  0x000CBA78A, // 43
  0x000D5B8A1, // 44
  0x000DFC9B8, // 45
  0x000E9DACF, // 46
  0x000F3EBE6, // 47
  0x000080A3B, // 48
  0x0000B0B57, // 49
  0x0000E0C73, // 50
  0x000110D8F, // 51
  0x000140EAB, // 52
  0x000170FC7, // 53
  0x0001A10E3, // 54
  0x0001D11FF, // 55
  0x000362BFF, // 56
  0x0004F45FF, // 57
  0x000685FFF, // 58
  0x0008179FF, // 59
  0x0009A93FF, // 60
  0x000B3ADFF, // 61
  0x000CCC7FF, // 62
  0x000E5E1FF, // 63
  0x00003373B, // 64
  0x000044F57, // 65
  0x000056773, // 66
  0x000067F8F, // 67
  0x0000797AB, // 68
  0x00008AFC7, // 69
  0x00009C7E3, // 70
  0x0000ADFFF, // 71
  0x00025E2FF, // 72
  0x00040E5FF, // 73
  0x0005BE8FF, // 74
  0x00076EBFF, // 75
  0x00091EEFF, // 76
  0x000ACF1FF, // 77
  0x000C7F4FF, // 78
  0x000E2F7FF, // 79
  0x000062E17, // 80
  0x000084422, // 81
  0x0000A5A2D, // 82
  0x0000C7038, // 83
  0x0000E8643, // 84
  0x000109C4E, // 85
  0x00012B259, // 86
  0x00014C864, // 87
  0x0002ECE75, // 88
  0x00048D486, // 89
  0x00062DA97, // 90
  0x0007CE0A8, // 91
  0x00096E6B9, // 92
  0x000B0ECCA, // 93
  0x000CAF2DB, // 94
  0x000E4F8EC, // 95
  0x0000A3907, // 96
  0x0000F5509, // 97
  0x00014710B, // 98
  0x000198D0D, // 99
  0x0001EA90F, // 100
  0x00023C511, // 101
  0x00028E113, // 102
  0x0002DFD15, // 103
  0x00044FD2F, // 104
  0x0005BFD49, // 105
  0x00072FD63, // 106
  0x00089FD7D, // 107
  0x000A0FD97, // 108
  0x000B7FDB1, // 109
  0x000CEFDCB, // 110
  0x000E5FDE5, // 111
  0x0002D3A0C, // 112
  0x00043560F, // 113
  0x000597212, // 114
  0x0006F8E15, // 115
  0x00085AA18, // 116
  0x0009BC61B, // 117
  0x000B1E21E, // 118
  0x000C7FE21, // 119
  0x000CDFE39, // 120
  0x000D3FE51, // 121
  0x000D9FE69, // 122
  0x000DFFE81, // 123
  0x000E5FE99, // 124
  0x000EBFEB1, // 125
  0x000F1FEC9, // 126
  0x000F7FEE1, // 127
  
  0x0003B3709, // 128
  0x00057500C, // 129
  0x00073690F, // 130
  0x0008F8212, // 131
  0x000AB9B15, // 132
  0x000C7B418, // 133
  0x000E3CD1B, // 134
  0x000FFE61E, // 135

  0x000FFE837, // 136
  0x000FFEA50, // 137
  0x000FFEC69, // 138
  0x000FFEE82, // 139
  
  0x000FFF09B, // 140
  0x000FFF2B4, // 141
  0x000FFF4CD, // 142
  0x000FFF6E6, // 143
  0x0003A1D04, // 144
  0x000562806, // 145
  0x000723308, // 146
  0x0008E3E0A, // 147
  
  0x000AA490C, // 148
  0x000C6540E, // 149
  0x000E25F10, // 150
  0x000FE6A12, // 151
  0x000FE7A2C, // 152
  0x000FE8A46, // 153
  0x000FE9A60, // 154
  0x000FEAA7A, // 155
  0x000FEBA94, // 156
  0x000FECAAE, // 157
  0x000FEDAC8, // 158
  0x000FEEAE3, // 159
  0x0003A0303, // 160
  0x000560403, // 161
  0x000720503, // 162
  0x0008E0603, // 163
  0x000AA0703, // 164
  0x000C60803, // 165
  0x000E20903, // 166
  0x000FE0A03, // 167
  0x000FE251F, // 168
  0x000FE403B, // 169
  0x000FE5B57, // 170
  0x000FE7673, // 171
  0x000FE918F, // 172
  0x000FEACAB, // 173
  0x000FEC7C7, // 174
  0x000FEE2E3, // 175
  0x0003A071D, // 176
  0x000560729, // 177
  0x000720735, // 178
  0x0008E0741, // 179
  0x000AA074D, // 180
  0x000C60759, // 181
  0x000E20765, // 182
  0x000FE0771, // 183
  0x000FE2280, // 184
  0x000FE3D8F, // 185
  0x000FE589E, // 186
  0x000FE73AD, // 187
  0x000FE8EBC, // 188
  0x000FEA9CB, // 189
  0x000FEC4DA, // 190
  0x000FEDFE9, // 191
  0x0003A042B, // 192
  0x00056063F, // 193
  0x000720853, // 194
  0x0008E0A67, // 195
  0x000AA0C7B, // 196
  0x000C60E8F, // 197
  0x000E210A3, // 198
  0x000FE12B7, // 199
  0x000FE2CBF, // 200
  0x000FE46C7, // 201
  0x000FE60CF, // 202
  0x000FE7AD7, // 203
  0x000FE94DF, // 204
  0x000FEAEE7, // 205
  0x000FEC8EF, // 206
  0x000FEE2F7, // 207
  0x00034063B, // 208
  0x0004A0757, // 209
  0x000600873, // 210
  0x00076098F, // 211
  0x0008C0AAB, // 212
  0x000A70BC7, // 213
  0x000B80CE3, // 214
  0x000CE0DFF, // 215
  0x000D327FF, // 216
  0x000D841FF, // 217
  0x000DD5BFF, // 218
  0x000E275FF, // 219
  0x000E78FFF, // 220
  0x000ECA9FF, // 221
  0x000F1C3FF, // 222
  0x000F6DDFF, // 223
  0x00024063B, // 224
  0x000360657, // 225
  0x000480673, // 226
  0x0005A068F, // 227
  0x0006C06AB, // 228
  0x0007E06C7, // 229
  0x0009006E3, // 230
  0x000A206FF, // 231
  0x000AC21FF, // 232
  0x000B63CFF, // 233
  0x000C057FF, // 234
  0x000CA72FF, // 235
  0x000D48DFF, // 236
  0x000DEA8FF, // 237
  0x000E8C3FF, // 238
  0x000FFDEF2, // 239
  0x0001C1C1C, // 240
  0x000282828, // 241
  0x000343434, // 242
  0x000404040, // 243
  0x0004C4C4C, // 244
  0x000585858, // 245
  0x000646464, // 246
  0x000707070, // 247
  0x0007F7F7F, // 248
  0x0008E8E8E, // 249
  0x0009D9D9D, // 250
  0x000ACACAC, // 251
  0x000BBBBBB, // 252
  0x000CACACA, // 253
  0x000D9D9D9, // 254
  0x000E8E8E8, // 255
};


		std::string Drawing::getColor(short color) {
			char stroke[8];
  			sprintf(stroke, "#%06x", DefaultPalette[color]);
			return std::string(stroke);
		}
		
		Paint Drawing::getFillStyle(short fillStyle, string color) {
			SvgElement defs = m_document.getDefsElement();
			return m_fcw.getFillStyle(defs, fillStyle, color);
		}
		
		void Drawing::initializeSvgDimensions(SvgElement& element) {
			float hypotenuse = sqrt(m_width * m_width + m_height * m_height);
			
			if (hypotenuse < 1600 && hypotenuse > 1000) {
				element.setAttribute("width", NumberUtil::formatFloat(getWidth()));
				element.setAttribute("height", NumberUtil::formatFloat(getHeight()));
			} else {
				float scale = 1200.0f / hypotenuse;
				element.setAttribute("width", NumberUtil::formatFloat(getWidth() * scale));
				element.setAttribute("height", NumberUtil::formatFloat(getHeight() * scale));
				
				string viewBox = string("0 0 ") + 
						NumberUtil::formatFloat(getWidth()) + " " + 
						NumberUtil::formatFloat(getHeight());
				element.setAttribute("viewBox", viewBox);
			}
			
		}
		
		float Drawing::getBaseStroke() {
			float hypotenuse = sqrt(m_width * m_width + m_height * m_height);
			float base = hypotenuse * 0.5f / 1200.0f;
			return base < 0.02f ? 0.02f : base;
		}
	}
}