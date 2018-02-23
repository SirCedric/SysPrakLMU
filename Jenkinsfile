pipeline {
  agent any
  stages {
    stage('Zeitstempel') {
      steps {
        timestamps()
      }
    }
    stage('Echo') {
      steps {
        sh '''echo IchBinDiePipline
'''
      }
    }
  }
}