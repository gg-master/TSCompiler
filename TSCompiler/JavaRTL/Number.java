package JavaRTL;

import java.text.DecimalFormat;

public class Number extends Any {
    public double _value = 0;

    public Number(int value) {
        this._value = value;
    }
    public Number(double value) {
        this._value = value;
    }
    public Number(java.lang.String value) {
        try {
            if (value.isEmpty()) {
                return;
            }
            int i = Integer.parseInt(value.trim());
            this._value = i;
        } catch (NumberFormatException nfe) {
            try {
                double d = Double.parseDouble(value.trim());
                this._value = d;
            } catch (NumberFormatException nfe2) {
                this._value = java.lang.Double.NaN;
            }
        }
    }

    public Number(Number value) {
        this._value = value._value;
    }
    public Number(JavaRTL.Boolean value) {
        this._value = value._value ? 1 : 0;
    }
    public Number(JavaRTL.String value) {
        this(value._value);
    }
    public Number(JavaRTL.Null value) {
        this._value = 0;
    }
    public Number(JavaRTL.Void value) {
        this._value = java.lang.Double.NaN;
    }

    public Number plus(Number other) {
        return new Number(this._value + other._value);
    }
    public JavaRTL.String plus(JavaRTL.String other) {
        return new String(this).plus(other);
    }
    public Number plus(JavaRTL.Null other) {
        return new Number(this._value);
    }
    public Number plus(JavaRTL.Undefined other) {
        return new Number(java.lang.Double.NaN);
    }

    public Number minus(Number other) {
        return new Number(this._value - other._value);
    }
    public Number minus(JavaRTL.Null other) {
        return new Number(this._value);
    }
    public Number minus(JavaRTL.Undefined other) {
        return new Number(java.lang.Double.NaN);
    }

    public Number mul(Number other) {
        return new Number(this._value * other._value);
    }
    public Number mul(JavaRTL.Null other) {
        return new Number(this._value);
    }
    public Number mul(JavaRTL.Undefined other) {
        return new Number(java.lang.Double.NaN);
    }

    public Number div(Number other) {
        return new Number(this._value / other._value);
    }
    public Number div(JavaRTL.Null other) {
        if (this._value > 0) {
            return new Number(java.lang.Double.POSITIVE_INFINITY);
        }
        return new Number(java.lang.Double.NEGATIVE_INFINITY);
    }
    public Number div(JavaRTL.Undefined other) {
        return new Number(java.lang.Double.NaN);
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
    public Boolean less(JavaRTL.Null other) {
        return new JavaRTL.Boolean(this._value < 0);
    }
    public Boolean less(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public Boolean great(Number other) {
        return new JavaRTL.Boolean(this._value > other._value);
    }
    public Boolean great(JavaRTL.Null other) {
        return new JavaRTL.Boolean(this._value > 0);
    }
    public Boolean great(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public Boolean equal(Number other) {
        return new JavaRTL.Boolean(this._value == other._value);
    }
    public Boolean equal(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }
    public Boolean equal(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public Boolean notEqual(Number other) {
        return new JavaRTL.Boolean(this._value != other._value);
    }
    public Boolean notEqual(JavaRTL.Null other) {
        return new JavaRTL.Boolean(true);
    }
    public Boolean notEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(true);
    }

    public Boolean lessEqual(Number other) {
        return new JavaRTL.Boolean(this._value <= other._value);
    }
    public Boolean lessEqual(JavaRTL.Null other) {
        return new JavaRTL.Boolean(this._value <= 0);
    }
    public Boolean lessEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public Boolean greatEqual(Number other) {
        return new JavaRTL.Boolean(this._value >= other._value);
    }
    public Boolean greatEqual(JavaRTL.Null other) {
        return new JavaRTL.Boolean(this._value >= 0);
    }
    public Boolean greatEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    @Override
    public java.lang.String toString() {
        DecimalFormat df = new DecimalFormat("#.##########");
        return df.format(this._value);
    }
}
