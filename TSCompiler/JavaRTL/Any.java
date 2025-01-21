package JavaRTL;

public class Any {

    // kostyl cause cant implement Exception table in bytecode and have no time
    public Any length() {
        return new Undefined();
    }

    public Any plus(Any other) {
        if (other == null) {
            other = new JavaRTL.Null();
        }
        if (other instanceof JavaRTL.String) {
            return new JavaRTL.String(this).plus(other);
        }
        if (this instanceof JavaRTL.Array || other instanceof JavaRTL.Array) {
            return new JavaRTL.String(this).plus(new JavaRTL.String(other));
        }
        return new JavaRTL.Number(this).plus(new JavaRTL.Number(other));
    }
    public JavaRTL.Number minus(Any other) {
        if (other == null) {
            other = new JavaRTL.Null();
        }
        return new JavaRTL.Number(this).minus(new JavaRTL.Number(other));
    }
    public JavaRTL.Number mul(Any other) {
        if (other == null) {
            other = new JavaRTL.Null();
        }
        return new JavaRTL.Number(this).mul(new JavaRTL.Number(other));
    }
    public JavaRTL.Number div(Any other) {
        if (other == null) {
            other = new JavaRTL.Null();
        }
        return new JavaRTL.Number(this).div(new JavaRTL.Number(other));
    }
    public JavaRTL.Number uPlus() {
        return new JavaRTL.Number(this).uPlus();
    }
    public JavaRTL.Number uMinus() {
        return new JavaRTL.Number(this).uMinus();
    }
    public JavaRTL.Boolean less(Any other) {
        if (other == null) {
            other = new JavaRTL.Null();
        }
        if (this instanceof JavaRTL.Array && other instanceof JavaRTL.Array) {
            return new JavaRTL.String(this).less(new JavaRTL.String(other));
        }
        return new JavaRTL.Number(this).less(new JavaRTL.Number(other));
    }
    public JavaRTL.Boolean great(Any other) {
        if (other == null) {
            other = new JavaRTL.Null();
        }
        if (this instanceof JavaRTL.Array && other instanceof JavaRTL.Array) {
            return new JavaRTL.String(this).great(new JavaRTL.String(other));
        }
        return new JavaRTL.Number(this).great(new JavaRTL.Number(other));
    }
    public JavaRTL.Boolean equal(Any other) {
        if (other == null) {
            other = new JavaRTL.Null();
        }
        if (this instanceof JavaRTL.Array && other instanceof JavaRTL.Array) {
            return new JavaRTL.Boolean(false);
        }
        return new JavaRTL.Number(this).equal(new JavaRTL.Number(other));
    }
    public JavaRTL.Boolean notEqual(Any other) {
        if (other == null) {
            other = new JavaRTL.Null();
        }
        if (this instanceof JavaRTL.Array && other instanceof JavaRTL.Array) {
            return new JavaRTL.Boolean(true);
        }
        return new JavaRTL.Number(this).notEqual(new JavaRTL.Number(other));
    }
    public JavaRTL.Boolean lessEqual(Any other) {
        if (other == null) {
            other = new JavaRTL.Null();
        }
        if (this instanceof JavaRTL.Array && other instanceof JavaRTL.Array) {
            return new JavaRTL.String(this).lessEqual(new JavaRTL.String(other));
        }
        return new JavaRTL.Number(this).lessEqual(new JavaRTL.Number(other));
    }
    public JavaRTL.Boolean greatEqual(Any other) {
        if (other == null) {
            other = new JavaRTL.Null();
        }
        if (this instanceof JavaRTL.Array && other instanceof JavaRTL.Array) {
            return new JavaRTL.String(this).greatEqual(new JavaRTL.String(other));
        }
        return new JavaRTL.Number(this).greatEqual(new JavaRTL.Number(other));
    }

    @Override
    public java.lang.String toString() {
        return "JavaRTL/Any";
    }
}