#ifndef CAM_MAN_H
#define CAM_MAN_H

//Abstract class

class CamMan {
	public:
	virtual void setZCenter(float zcent) = 0;
	virtual void load() = 0;
	virtual void loadInv() = 0;
	virtual void setEyeCoords(float x, float y, float z) = 0;
	virtual void setCameraTransf(float* mat) = 0;
};

#endif /* CAM_MAN_H */
