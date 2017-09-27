pandoc --from markdown --to latex README.md -o Documentation/readme.tex
cd Documentation
pdflatex .\BrowsableStoreAnalytics.tex
pdflatex .\BrowsableStoreAnalytics.tex
