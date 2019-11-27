pipeline {
  environment {
    registry = "sensedata1/audioformatdetective"
    registryCredential = 'dockerhub'
    dockerImage = ''
    runCommand = "docker run -v ~/AJTEMP:/AJTEMP -it sensedata1/audioformatdetective"
    destFile = "run.sh"
  }
  agent any
  stages {
    stage('Cloning Git') {
      steps {
        git 'https://github.com/sensedata1/audioformatdetectivedocker.git'
      }
    }
    stage('Building image') {
      steps{
        script {
          dockerImage = docker.build registry + ":$BUILD_NUMBER"

        }
      }
    }
    stage('Deploy Image') {
      steps{
        script {
          docker.withRegistry( '', registryCredential ) {
            dockerImage.push()
          }
        }
      }
    }
    stage('Remove Unused docker image') {
      steps{
        sh "docker rmi $registry:$BUILD_NUMBER"

      }
    }
    stage('Increment build number in run.sh') {
      steps{
         sh "$runCommand:$BUILD_NUMBER > $destFile"

      }
    }
  }
}
