function Search (P: BinTree, X: infotype) → boolean{
/* Mengirimkan true jika ada node dari P yang bernilai X */
	if (IsTreeEmpty(P)) return false;
	else {
		if (Akar(P) == X) {
			return true;
		} else {
			return (Search(Left(P), X) || Search(Right(P), X));
		}
	}
}

function IsSkewLeft (P: BinTree) → boolean{
/* Mengirimkan true jika P adalah pohon condong kiri */	
	if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (IsOneElmt(P)) {
			return true;
		} else if (IsUnerLeft(P)) {
			return IsSkewLeft(Left(P));
		} else {
			return false;
		}
	}
}

function IsSkewRight (P: BinTree) → boolean{
/* Mengirimkan true jika P adalah pohon condong kanan */	
	if (IsTreeEmpty(P)) {
		return false;
	} else {
		if (IsOneElmt(P)) {
			return true;
		} else if (IsUnerRight(P)) {
			return IsSkewRight(Right(P));
		} else {
			return false;
		}
	}
}

function Level (P: BinTree, X: infotype) → integer {
/* Mengirimkan level dari node X yang merupakan salah satu daun dari pohon biner P.
Akar(P) level-nya adalah 1. Pohon P tidak kosong dan elemen-elemennya unik. */
	if (IsTreeEmpty(P))	return 0;
	if (Akar(P)==X) return 1;
	else {
		if (SearchTree(Left(P),X))
			return (Level(Left(P),X)+1);
		else
			return (Level(Right(P),X)+1);
	}
}


procedure AddDaun (input/Output P: BinTree, input X, Y: infotype, input Kiri: boolean) {
/* I.S. P tidak kosong, X adalah daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri), atau sebagai
anak Kanan X (jika not Kiri). Jika ada lebih dari satu daun bernilai X, Y ditambahkan
pada daun paling kiri. */
	if (!IsTreeEmpty(*P)) {
		if (Akar(*P) == X) {
			if (Kiri) {
				Left(*P)= Tree(Y, Nil, Nil);
			} else {
				Right(*P)= Tree(Y, Nil, Nil);
			}
		} else {
			AddDaun(&Left(*P), X, Y, Kiri);
			AddDaun(&Right(*P), X, Y, Kiri);
		}
	}
}

procedure DelDaun (input/output P: BinTree, input X: infotype) {
/* I.S. P tidak kosong, minimum 1 daun bernilai X, F.S. Semua daun yang bernilai X dihapus dari P */
	if (!IsTreeEmpty(*P)) {
		if (Akar(*P) == X) {
			free(*P);
			*P= Nil;
		} else {
			DelDaun(&Left(*P), X);
			DelDaun(&Right(*P), X);
		}
	}
}