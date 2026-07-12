library: main.o addbook.o removebook.o updatebook.o searchbook.o viewbook.o issuebook.o returnbook.o listIssuedBooks.o savebook.o loadbook.o saveissues.o loadissues.o getCurrentDate.o calculateDueDate.o calculateFine.o lib_exit.o
	cc main.o addbook.o removebook.o updatebook.o searchbook.o viewbook.o issuebook.o returnbook.o listIssuedBooks.o savebook.o loadbook.o saveissues.o loadissues.o getCurrentDate.o calculateDueDate.o calculateFine.o lib_exit.o -o library
main.o: main.c
	cc -c main.c
addbook.o: addbook.c
	cc -c addbook.c
removebook.o: removebook.c
	cc -c removebook.c
updatebook.o: updatebook.c
	cc -c updatebook.c
searchbook.o: searchbook.c
	cc -c searchbook.c
viewbook.o: viewbook.c
	cc -c viewbook.c
issuebook.o: issuebook.c
	cc -c issuebook.c
returnbook.o: returnbook.c
	cc -c returnbook.c
listIssuedBooks.o: listIssuedBooks.c
	cc -c listIssuedBooks.c
savebook.o:  savebook.c
	cc -c savebook.c
loadbook.o: loadbook.c
	cc -c loadbook.c
saveissues.o: saveissues.c
	cc -c saveissues.c
loadissues.o:  loadissues.c
	cc -c  loadissues.c
getCurrentDate.o: getCurrentDate.c
	cc -c getCurrentDate.c
calculateDueDate.o:  calculateDueDate.c
	cc -c  calculateDueDate.c
calculateFine.o: calculateFine.c
	cc -c calculateFine.c
lib_exit.o: lib_exit.c
	cc -c lib_exit.c


		

