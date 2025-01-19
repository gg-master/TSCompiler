package JavaRTL;

public class Void extends Any {
    public JavaRTL.String plus(JavaRTL.String other) {
        return new JavaRTL.String(this).plus(other);
    }
    public JavaRTL.Number plus(JavaRTL.Null other) {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number plus(JavaRTL.Undefined other) {
        return new JavaRTL.Number(this);
    }

    public JavaRTL.Number uPlus() {
        return new JavaRTL.Number(this);
    }
    public JavaRTL.Number uMinus() {
        return new JavaRTL.Number(this);
    }

    public JavaRTL.Boolean less(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean less(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean great(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean great(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean equal(JavaRTL.Void other) {
        return new JavaRTL.Boolean(true);
    }
    public JavaRTL.Boolean equal(JavaRTL.Null other) {
        return new JavaRTL.Boolean(true);
    }

    // that method not adding into ASI
    public JavaRTL.Boolean equal(Any other) {
        if (other instanceof JavaRTL.Void || other instanceof JavaRTL.Null) {
            return new JavaRTL.Boolean(true);
        }
        return super.equal(other);
    }

    public JavaRTL.Boolean notEqual(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean notEqual(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }

    // that method not adding into ASI
    public JavaRTL.Boolean notEqual(Any other) {
        if (other instanceof JavaRTL.Void || other instanceof JavaRTL.Null) {
            return new JavaRTL.Boolean(false);
        }
        return super.notEqual(other);
    }

    public JavaRTL.Boolean lessEqual(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean lessEqual(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }

    public JavaRTL.Boolean greatEqual(JavaRTL.Void other) {
        return new JavaRTL.Boolean(false);
    }
    public JavaRTL.Boolean greatEqual(JavaRTL.Null other) {
        return new JavaRTL.Boolean(false);
    }

    @Override
    public java.lang.String toString() {
        return "undefined";
    }
}
