#ifndef _CIMAGE_H_
#define _CIMAGE_H_

/** Klasa reprezentujaca obraz wyjsciowy
*/
class CImage {
private:
	FIBITMAP* data;
	int width; /**< liczba pikseli w poziomie */
	int height; /**< liczba pikseli w pionie */
public:
	CImage(int width, int height);
	/** Zapisanie obrazu w pliku dyskowym
	*	@param fname - nazwa pliku
	*/
	void save(char* fname);
	void setPixel(int i, int j, RGBQUAD color);
};

#endif