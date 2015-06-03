

heat_map <- function(filename, title, tile) {
  foo <- read.table(filename, sep = "\t", header = T)

  #CHANGE FOR LANE NUMBER
  foo <- foo[foo$lane == 1,]

  #Change for tile number
  foo <- foo[foo$tile == tile,]

  
  #make sure you install MBA library
  library(MBA)

  foo <- data.frame(foo[,3], foo[,4], foo[,5])
  foo<-foo[order(foo[,1], foo[,2], foo[,3]), ]
  mba.int <- mba.surf(foo, 500, 500, extend=T)$xyz.est


  #make sure you install fields library  
  library(fields)

  par(mar=c(2,2,2,2))
  png(paste(title, ".png", sep = ""))
  fields::image.plot(mba.int, main = title, xlab = "X axis of Tile", ylab = "Y axis of Tile", zlim = c(0, 40), xlim = c(0, 30000), ylim = c(0, 30000))
  dev.off()



}

options(echo=T)
args <- commandArgs(T)
print(args)
heat_map(args[1], args[2], args[3])

read_densities <- function(filename, title, tile) {
  library(aqfig)
  print(tile)
  foo <- read.table(filename, sep = "\t")
  scatterplot.density(foo$V1, foo$V2, main = title, xlab = "X axis", ylab = "Y axis", ylim = c(0, 30000), xlim = c(0, 30000))  
}
