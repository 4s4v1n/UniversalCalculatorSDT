function hexCharacterToDecimal(character) {
    if (character === "A" || character === "a") {
        return 10
    }
    if (character === "B" || character === "b") {
        return 11
    }
    if (character === "C" || character === "c") {
        return 12
    }
    if (character === "D" || character === "d") {
        return 13
    }
    if (character === "E" || character === "e") {
        return 14
    }
    if (character === "F" || character === "f") {
        return 15
    }
    return Number(character)
}

function hexDecimalToUpperCharacter(decimal) {
    return String.fromCharCode(54 + decimal)
}

function hexDecimalToLowerCharacter(decimal) {
    return String.fromCharCode(86 + decimal)
}

function regexFromBase(base) {
    if (base < 2 || base > 16) {
        throw "invalid base"
    }

    if (base <= 10) {
        return new RegExp(`(^-?[0-${base -1}]+(\\.[0-${base -1}]+)?)` +
                          `(((-|\\+|\\*|/)` +
                          `-?[0-${base -1}]+(\\.[0-${base -1}]+)?)|` +
                          `(\\^|~))$`)
    }
    else {
        return new RegExp(`(^-?[0-9a-${hexDecimalToLowerCharacter(base)}A-${hexDecimalToUpperCharacter(base)}]+` +
                          `(\\.[0-9a-${hexDecimalToLowerCharacter(base)}A-${hexDecimalToUpperCharacter(base)}]+)?)` +
                          `(((-|\\+|\\*|/)` +
                          `-?[0-9a-${hexDecimalToLowerCharacter(base)}A-${hexDecimalToUpperCharacter(base)}]+` +
                          `(\\.[0-9a-${hexDecimalToLowerCharacter(base)}A-${hexDecimalToUpperCharacter(base)}]+)?)|` +
                          `(\\^|~))$`)
    }
}
