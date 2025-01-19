package JavaRTL;

import java.text.DecimalFormat;

public class Number extends Any {

    public double _value = 0;

    public Number() {}

    public Number(int value) {
        this._value = value;
    }
    public Number(double value) {
        this._value = value;
    }
    public Number(java.lang.String value) {
        this._value = parseString(value);
    }

    public Number(Any value) {
        if (value == null) {
            value = new JavaRTL.Null();
        }
        if (value instanceof Number) {
            this._value = ((Number)value)._value;
        } else if (value instanceof JavaRTL.Boolean) {
            this._value = ((JavaRTL.Boolean)value)._value ? 1 : 0;
        } else if (value instanceof JavaRTL.String) {
            this._value = Number.parseString(((JavaRTL.String)value)._value);
        } else if (value instanceof JavaRTL.Null) {
            this._value = 0;
        } else if (value instanceof JavaRTL.Void) {
            this._value = java.lang.Double.NaN;
        }
    }

    private static double parseString(java.lang.String value) {
        try {
            if (value.isEmpty()) {
                return 0;
            }
            return Double.parseDouble(value.trim());
        } catch (NumberFormatException nfe) {
            return java.lang.Double.NaN;
        }
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
        if (other._value != 0) {
            return new Number(this._value / other._value);
        }

        if (this._value == 0) {
            return new Number(java.lang.Double.NaN);
        }
        if (this._value > 0) {
            return new Number(java.lang.Double.POSITIVE_INFINITY);
        }
        return new Number(java.lang.Double.NEGATIVE_INFINITY);
        
    }
    public Number div(JavaRTL.Null other) {
        if (this._value == 0) {
            return new Number(java.lang.Double.NaN);
        }
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

    public int toInt() {
        return (int)this._value;
    }

    @Override
    public java.lang.String toString() {
        if (java.lang.Double.isNaN(this._value)) {
            return "NaN";
        }
        if (java.lang.Double.isInfinite(this._value)) {
            return this._value > 0 ? "Infinity" : "-Infinity";
        }
        DecimalFormat df = new DecimalFormat("#.##########");
        return df.format(this._value);
    }
}
