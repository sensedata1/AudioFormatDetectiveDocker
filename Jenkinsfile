pipeline {
  environment {
    registry = "sensedata1/audioformatdetective"
    registryCredential = 'dockerhub'
    dockerImage = ''
    runCommand = "docker run -v "/Volumes/ProjectsDrive/General Downloads/AJ TEMP DOWNLOADS":/AJTEMP -it sensedata1/audioformatdetective"
    destFile = "run.sh"
    imageToPush = ''
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
             dockerImage = docker.build("$registry:prod" ,  " --squash -f Dockerfile . ")
//           dockerImage = docker.build + registry + ":$BUILD_NUMBER"

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
        sh "docker rmi $registry:prod"

      }
    }
    stage('Increment build number in run.sh') {
      steps{
         sh 'printf "%s" "$runCommand:prod" > "$destFile"'

      }
    }
  }
}
