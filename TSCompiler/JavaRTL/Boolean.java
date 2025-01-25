package JavaRTL;

public class Boolean extends Any {
    public boolean _value = false;

    public JavaRTL.Any origValue;

    public Boolean() { this.origValue = this; }
    
    public Boolean(boolean value){
        this._value = value;
        this.origValue = this;
    }
    public Boolean(int value){
        this._value = value != 0;
        this.origValue = new Number(value);
    }
    public Boolean(java.lang.String value) {
        this(!value.isEmpty());
        this.origValue = new JavaRTL.String(value);
    }

    public Boolean(JavaRTL.Any value) {
        if (value == null) {
            value = new JavaRTL.Null();
        }
        this.origValue = value;

        if (value instanceof Boolean) {
            this._value = ((Boolean)value)._value;
        } else if (value instanceof JavaRTL.Number) {
            this._value = ((JavaRTL.Number)value)._value != 0;
        } else if (value instanceof JavaRTL.String) {
            this._value = !((JavaRTL.String)value)._value.isEmpty();
        } else if (value instanceof JavaRTL.Null) {
            this._value = false;
        } else if (value instanceof JavaRTL.Void) {
            this._value = false;
        } else {
            this._value = true;
        }
    }

    // not removed because that functions may use when user write type of variable

    public JavaRTL.String plus(JavaRTL.String other) {
        return new String(this).plus(other);
    }
    public JavaRTL.Number plus(JavaRTL.Null other) {
        return new Number(this);
    }
    public JavaRTL.Number plus(JavaRTL.Undefined other) {
        return new Number(other);
    }

    public Boolean less(Boolean other) {
        return (new Number(this)).less(new Number(other));
    }
    public Boolean less(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }
    public Boolean less(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public Boolean great(Boolean other) {
        return (new Number(this)).great(new Number(other));
    }
    public Boolean great(JavaRTL.Null other) {
        return (new Number(this)).great(new Number(other));
    }
    public Boolean great(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public Boolean equal(Boolean other) {
        return new Boolean(this._value == other._value);
    }
    public Boolean equal(JavaRTL.Null other) {
        return new Boolean(false);
    }
    public Boolean equal(JavaRTL.Undefined other) {
        return new Boolean(false);
    }
    public Boolean equal(Any other) {
        if (other instanceof JavaRTL.Void || other instanceof JavaRTL.Null) {
            return new JavaRTL.Boolean(false);
        }
        return super.equal(other);
    }

    public Boolean notEqual(Boolean other) {
        return new Boolean(this._value != other._value);
    }
    public Boolean notEqual(JavaRTL.Null other) {
        return new Boolean(true);
    }
    public Boolean notEqual(JavaRTL.Undefined other) {
        return new Boolean(true);
    }
    public Boolean notEqual(Any other) {
        if (other instanceof JavaRTL.Void || other instanceof JavaRTL.Null) {
            return new JavaRTL.Boolean(true);
        }
        return super.notEqual(other);
    }

    public Boolean lessEqual(Boolean other) {
        return (new Number(this)).lessEqual(new Number(other));
    }
    public Boolean lessEqual(JavaRTL.Null other) {
        return (new Number(this)).lessEqual(new Number(other));
    }
    public Boolean lessEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public Boolean greatEqual(Boolean other) {
        return (new Number(this)).greatEqual(new Number(other));
    }
    public Boolean greatEqual(JavaRTL.Null other) {
        return (new Number(this)).greatEqual(new Number(other));
    }
    public Boolean greatEqual(JavaRTL.Undefined other) {
        return new JavaRTL.Boolean(false);
    }

    public Boolean not() {
        return new Boolean(!this._value);
    }

    public boolean getValue() {
        return this._value;
    }

    @Override
    public java.lang.String toString() {
        return java.lang.String.valueOf(this._value);
    }
}
