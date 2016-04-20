
/** Klasa opisujaca scene, definicje kamery, zrodel swiatla, obiektow, itp.
*/
class CScene {
public:
	CCamera* cam; /**< kamera */

	vector<CObject*> obj; /**< lista z definicjami obiektow */
	int objCount; /**< liczba obiektow na liscie */

	CLight* lights[10];
	int lightCount;


	/** Parsowanie pliku tektowego z informacjami o cenie.
	*	@param - nazwa pliku
	*/
	int parse(char* fname);
public:
	CScene(CCamera* cam, vector<CObject*> obj);
	

};