#pragma once
class AssemblyLine
{
public:
	AssemblyLine();
	void Start() const;

private:
	std::vector<std::pair<Box, uint>> preparePaintOrder(Boxes boxes, TupleVec order) const;
	double getTotalVolume(Boxes boxes) const;
	double getTotalSurfaceArea(Boxes boxes) const;
	void displayColorWiseInfo(Boxes finished) const;

private:
	std::map<uint, std::string> colorCodeToColorName;

};

