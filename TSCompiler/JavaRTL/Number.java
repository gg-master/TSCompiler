package JavaRTL;

public class Number extends Any {
    public double _value;

    public Number(int value) {
        this._value = value;
    }

    public Number(double value) {
        this._value = value;
    }

    public Number(java.lang.String value) {
        try {
            int i = Integer.parseInt(value.trim());
            this._value = i;
        } catch (NumberFormatException nfe) {
            try {
                double d = Double.parseDouble(value.trim());
                this._value = d;
            } catch (NumberFormatException nfe2) {
                throw new NumberFormatException("Unable to parse value as int or double: " + value);
            }
        }
    }

    public Number plus(Number other) {
        return new Number(this._value + other._value);
    }

    public Number minus(Number other) {
        return new Number(this._value - other._value);
    }

    public Number mul(Number other) {
        return new Number(this._value * other._value);
    }

    public Number div(Number other) {
        return new Number(this._value / other._value);
    }

    public Number uPlus() {
        return new Number(+this._value);
    }

    public Number uMinus() {
        return new Number(-this._value);
    }

    public Boolean less(Number other) {
        return new JavaRTL.Boolean(this._value < other._value);
    }

    public Boolean great(Number other) {
        return new JavaRTL.Boolean(this._value > other._value);
    }

    public Boolean equal(Number other) {
        return new JavaRTL.Boolean(this._value != other._value);
    }

    public Boolean notEqual(Number other) {
        return new JavaRTL.Boolean(this._value != other._value);
    }

    public Boolean lessEqual(Number other) {
        return new JavaRTL.Boolean(this._value <= other._value);
    }

    public Boolean greatEqual(Number other) {
        return new JavaRTL.Boolean(this._value >= other._value);
    }

    @Override
    public java.lang.String toString() {
        return java.lang.String.valueOf(this._value);
    }
}
