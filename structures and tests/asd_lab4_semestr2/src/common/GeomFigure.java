package common;

/**
 * Class represents geometric figure such as rectangle or triangle. Contains
 * coordinates of figure and methods to calculate area and perimeter
 */
public class GeomFigure {


	private double length;
	private double centerX;
	private double centerY;
	private double radius;
	private int hash = 0;

	public GeomFigure(double centerX, double centerY, double radius) {
		this.centerX = centerX;
		this.centerY = centerY;
		this.radius = radius;
		this.length = Math.PI * radius * 2;
		this.hash = hashCode();
	}
	public GeomFigure(GeomFigure toCopy) {
		this.centerX = toCopy.centerX;
		this.centerY = toCopy.centerY;
		this.radius = toCopy.radius;
		this.length = Math.PI * radius * 2;
		this.hash = hashCode();
	}


	/**
	 * Returns the hash code length for this geometric figure. The hash code of a
	 * figure is defined to be the sum of the hash codes of the elements in the
	 * figure, where the hash code of a null element is defined to be zero.
	 * 
	 * @return the hash code length for this object
	 */
	public int hashCode() {
		if (hash == 0) {
			hash = 31 * Double.hashCode(length);
			hash = hash * 31 + Double.hashCode(centerX);
			hash = hash * 31 + Double.hashCode(centerY);
			hash = hash * 31 + Double.hashCode(radius);
		}

		return Math.abs(hash);
	}

	@Override
	public String toString() {
		return String.format("hash :%-10s|length:  %-6.2f|centerX  %-6.2f|centerY  %-6.2f|radius:  %-6.2f|",
				hash, length, centerX, centerY, radius);
	}


	public boolean equals(GeomFigure gf) {
		if (this == gf) return true;
		if(gf == null) return false;
		if (Double.compare(gf.length, length) != 0) return false;
		if (Double.compare(gf.centerX, centerX) != 0) return false;
		if (Double.compare(gf.centerY, centerY) != 0) return false;
		if (Double.compare(gf.radius, radius) != 0) return false;
		return hash == gf.hash;

	}

}
