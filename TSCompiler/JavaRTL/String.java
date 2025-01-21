package JavaRTL;

public class String extends Any {

    public java.lang.String _value = "";

    public String() {}

    public String(int value){
        this._value = java.lang.String.valueOf(value);
    }

    public String(double value){
        this._value = java.lang.String.valueOf(value);
    }

    public String(java.lang.String value){
        this._value = value;
    }

    public String(JavaRTL.Any value){
        if (value == null) {
            value = new JavaRTL.Null();
        }
        this._value = value.toString();
    }

    public String plus(JavaRTL.Any other) {
        return new String(this._value + (new String(other))._value);
    }

    public JavaRTL.Boolean less(String other) {
        boolean result = this._value.compareTo(other._value) < 0;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean less(JavaRTL.Null other) {
        return (new JavaRTL.Number(this)).less(new Number(other));
    }
    public JavaRTL.Boolean less(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    // that method not adding into ASI
    public JavaRTL.Boolean less(Any other) {
        if (other instanceof JavaRTL.Array) {
            other = new String(other);
        }
        if (other instanceof String) {
            boolean result = this._value.compareTo(((String)other)._value) < 0;
            return new JavaRTL.Boolean(result);
        }
        return super.less(other);       
    }

    public JavaRTL.Boolean great(String other) {
        boolean result = this._value.compareTo(other._value) > 0;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean great(JavaRTL.Null other) {
        return (new JavaRTL.Number(this)).great(new Number(other));
    }
    public JavaRTL.Boolean great(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    // that method not adding into ASI
    public JavaRTL.Boolean great(Any other) {
        if (other instanceof JavaRTL.Array) {
            other = new String(other);
        }
        if (other instanceof String) {
            boolean result = this._value.compareTo(((String)other)._value) > 0;
            return new JavaRTL.Boolean(result);
        }
        return super.great(other);       
    }

    public JavaRTL.Boolean equal(String other) {
        boolean result = this._value.compareTo(other._value) == 0;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean equal(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean equal(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    // that method not adding into ASI
    public JavaRTL.Boolean equal(Any other) {
        if (other instanceof JavaRTL.Array) {
            other = new String(other);
        }
        if (other instanceof String) {
            boolean result = this._value.compareTo(((String)other)._value) == 0;
            return new JavaRTL.Boolean(result);
        }
        if (other instanceof JavaRTL.Void || other instanceof JavaRTL.Null) {
            return new JavaRTL.Boolean(false);
        }
        return super.equal(other);       
    }

    public JavaRTL.Boolean notEqual(String other) {
        boolean result = this._value.compareTo(other._value) != 0;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Null other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(true);
    }

    // that method not adding into ASI
    public JavaRTL.Boolean notEqual(Any other) {
        if (other instanceof JavaRTL.Array) {
            other = new String(other);
        }
        if (other instanceof String) {
            boolean result = this._value.compareTo(((String)other)._value) != 0;
            return new JavaRTL.Boolean(result);
        }
        if (other instanceof JavaRTL.Void || other instanceof JavaRTL.Null) {
            return new JavaRTL.Boolean(true);
        }
        return super.notEqual(other);       
    }

    public JavaRTL.Boolean lessEqual(String other) {
        boolean result = this._value.compareTo(other._value) <= 0;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Null other) {
        return (new JavaRTL.Number(this)).lessEqual(new Number(other));
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    // that method not adding into ASI
    public JavaRTL.Boolean lessEqual(Any other) {
        if (other instanceof JavaRTL.Array) {
            other = new String(other);
        }
        if (other instanceof String) {
            boolean result = this._value.compareTo(((String)other)._value) <= 0;
            return new JavaRTL.Boolean(result);
        }
        return super.lessEqual(other);       
    }

    public JavaRTL.Boolean greatEqual(String other) {
        boolean result = this._value.compareTo(other._value) >= 0;
        return new JavaRTL.Boolean(result);
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Null other) {
        return (new JavaRTL.Number(this)).greatEqual(new Number(other));
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    // that method not adding into ASI
    public JavaRTL.Boolean greatEqual(Any other) {
        if (other instanceof JavaRTL.Array) {
            other = new String(other);
        }
        if (other instanceof String) {
            boolean result = this._value.compareTo(((String)other)._value) >= 0;
            return new JavaRTL.Boolean(result);
        }
        return super.greatEqual(other);       
    }

    @Override
    public java.lang.String toString() {
        return this._value;
    }
}
